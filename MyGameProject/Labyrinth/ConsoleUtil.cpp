#include "ConsoleUtil.h"

void HideCursor()
{
	//CONSOLE_CURSOR_INFO info;
	//info.bVisible = false; // 안보이게
	//info.dwSize = 1; //커서의 크기값
	//SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;  // 커서 안 보이게
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void SetCurPosition(int x, int y)
{
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
