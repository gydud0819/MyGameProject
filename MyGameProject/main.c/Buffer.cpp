#include "Buffer.h"

int screenIndex = 0;         // 여기서 메모리 "정의 + 초기화" 동시에 함,  // 현재 활성화된 콘솔 버퍼의 인덱스 (0 또는 1)
HANDLE hBuffer[2];           // 콘솔 화면 버퍼를 2개 생성해서 번갈아가며 사용 (더블 버퍼링)

// 콘솔 버퍼 2개를 생성하고 초기화하는 함수
void InitBuffer()
{
    //현재 스크린 index값은 0
    screenIndex = 0;

    // 콘솔 버퍼의 크기
    COORD size = { BufferWidth, BufferHeight };

    // 콘솔 창의 출력 영역 설정
    SMALL_RECT rect = { 0, 0, BufferWidth - 1, BufferHeight - 1 };

    // 첫 번째 버퍼 생성 및 설정
    hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(hBuffer[0], size);   // 버퍼 크기 설정
    SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);  // 콘솔 윈도우 영역 설정

    // 두 번째 버퍼 생성 및 설정
    hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(hBuffer[1], size);
    SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

    // 커서 정보 설정 (커서 보이지 않게)
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = FALSE;

    SetConsoleCursorInfo(hBuffer[0], &info);
    SetConsoleCursorInfo(hBuffer[1], &info);

    // 버퍼 생성 실패 시 종료
    if (hBuffer[0] == INVALID_HANDLE_VALUE || hBuffer[1] == INVALID_HANDLE_VALUE)
    {
        std::cerr << "콘솔 버퍼 생성 실패!" << std::endl;
        exit(1);
    }

}

// 버퍼 뒤집기 0->1, 1->0
void FlipBuffer()   
{
    // 해당 버퍼 활성화
    SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);

    //  0->1, 1->0 (토글)
    screenIndex = !screenIndex;
}

// 현재 버퍼의 모든 내용을 공백으로 채워 초기화하는 함수
void ClearBuffer()
{
    COORD pos = { 0,0 };    // 시작 위치
    DWORD dw;                // 실제 출력된 문자 수

    // 화면 전체를 공백 문자로 채우기
    FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

// 현재 버퍼에 문자열을 출력하는 함수
void WriteBuffer(int x, int y, const char* shape, int color)
{
    COORD pos = { x * 2, y };   // x 좌표를 2배 해서 가독성 확보하기 (한글과 같은 문자는 2 byte를 차지함)

    SetConsoleCursorPosition(hBuffer[screenIndex], pos);    // 커서 위치 설정
    SetConsoleTextAttribute(hBuffer[screenIndex], color);   // 색상 설정

    DWORD dw;   // 실제 출력된 문자 수
    WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);   // shape 문자열 출력
}

// 맵을 가운데로 옮기기 위한 임시 버퍼 함수 // 얘도안됨 시바꺼 진짜 
void WriteBuffer(int x, int y)
{
    COORD pos = { x * 2, y };
}


// 프로그램 종료 시 콘솔 버퍼 자원 해제
void ReleaseBuffer()
{
    CloseHandle(hBuffer[0]);
    CloseHandle(hBuffer[1]);
}
