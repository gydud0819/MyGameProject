#include "DoubleBuffer.h"


int screenIndex = 0;         // 여기서 메모리 "정의 + 초기화" 동시에 함,  // 현재 활성화된 콘솔 버퍼의 인덱스 (0 또는 1)
HANDLE hBuffer[2];           // 콘솔 화면 버퍼를 2개 생성해서 번갈아가며 사용 (더블 버퍼링)

void SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // 현재 콘솔 크기 받아오기

    // 콘솔 글자 크기 계산
    CONSOLE_FONT_INFO cfi;
    GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    int charWidth = cfi.dwFontSize.X;
    int charHeight = cfi.dwFontSize.Y;

    // 창 크기 조정 (글자 수 * 글자 픽셀 크기)
    MoveWindow(console, r.left, r.top, width * charWidth, height * charHeight, TRUE);
}

// 콘솔 버퍼 2개를 생성하고 초기화하는 함수
void InitBuffer()
{
    SetConsoleSize(BufferWidth, BufferHeight);

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
    //FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
    //FillConsoleOutputAttribute(hBuffer[screenIndex], 0, BufferWidth * BufferHeight, pos, &dw);

    // 더 큰 콘솔에 대응하기 위해 넉넉하게 지우기
    FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', 300 * 100, pos, &dw);
    FillConsoleOutputAttribute(hBuffer[screenIndex], 0, 300 * 100, pos, &dw);
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



// 프로그램 종료 시 콘솔 버퍼 자원 해제
void ReleaseBuffer()
{
    CloseHandle(hBuffer[0]);
    CloseHandle(hBuffer[1]);
}

void WriteCenter(const char* text, int yOffset, int color)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int x = (windowWidth - strlen(text)) / 2;
    int y = (windowHeight / 2) + yOffset;

    WriteBuffer(x, y, text, color);
}
