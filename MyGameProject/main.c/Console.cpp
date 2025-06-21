#include "Console.h"
#include "Buffer.h"

void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor)
{
	if (_BackGroundColor > 15 || _Textcolor > 15) return;	// 1000

	unsigned short ColorNum = (_BackGroundColor << 4) | _Textcolor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

//커서 이동 함수
void SetCurPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;	// x는 x2를 해야 한칸이 된다.
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 숨기기 함수
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false; // 안보이게
	info.dwSize = 1; //커서의 크기값
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Startscreen()
{
	ClearBuffer();// 또는 ClearBuffer() + FlipBuffer()
	FlipBuffer();

	const char* title = "◆◆◆ Maze Escape ◆◆◆";
	const char* prompt = "[ Press any key to start ]";

	int x = (BufferWidth - strlen(title)) / 2;
	int y = BufferHeight / 2 - 4;

	WriteBuffer(x, y, title, 14);      // 노란색
	WriteBuffer(x, y + 2, prompt, 7);  // 흰색
	FlipBuffer();

	_getch(); // 아무 키 누를 때까지 대기
}



void ClearScreen()
{
	COORD cursorPosition = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
