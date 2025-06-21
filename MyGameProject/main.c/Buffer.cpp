#include "Buffer.h"

int screenIndex = 0;         // 여기서 메모리 "정의 + 초기화" 동시에 함
HANDLE hBuffer[2];

void InitBuffer()
{
    screenIndex = 0;

    COORD size = { BufferWidth, BufferHeight };

    SMALL_RECT rect = { 0, 0, BufferWidth - 1, BufferHeight - 1 };

    hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(hBuffer[0], size);
    SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

    hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(hBuffer[1], size);
    SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = FALSE;

    SetConsoleCursorInfo(hBuffer[0], &info);
    SetConsoleCursorInfo(hBuffer[1], &info);

    if (hBuffer[0] == INVALID_HANDLE_VALUE || hBuffer[1] == INVALID_HANDLE_VALUE)
    {
        std::cerr << "콘솔 버퍼 생성 실패!" << std::endl;
        exit(1);
    }

}

void FlipBuffer()
{
    SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);

    screenIndex = !screenIndex;
}

void ClearBuffer()
{
    COORD pos = { 0,0 };
    DWORD dw;

    FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', BufferWidth * BufferHeight, pos, &dw);
}

void WriteBuffer(int x, int y, const char* shape, int color)
{
    COORD pos = { x * 2, y };

    SetConsoleCursorPosition(hBuffer[screenIndex], pos);
    SetConsoleTextAttribute(hBuffer[screenIndex], color);

    DWORD dw;
    WriteFile(hBuffer[screenIndex], shape, strlen(shape), &dw, NULL);
}

void ReleaseBuffer()
{
    CloseHandle(hBuffer[0]);
    CloseHandle(hBuffer[1]);
}
