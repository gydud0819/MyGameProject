#include "Console.h"
#include "Buffer.h"

void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor)
{
	if (_BackGroundColor > 15 || _Textcolor > 15) return;	// 1000

	unsigned short ColorNum = (_BackGroundColor << 4) | _Textcolor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

//커서 이동 함수
void SetCurPosition(int x, int y)		// 이걸로 나중에 맵 위치 옮기기 
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

// 중앙 정렬로 WriteBuffer 해주는 함수
void WriteCenter(const char* text, int yOffset, int color = 7)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	int windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	int x = (windowWidth - strlen(text)) / 2;
	int y = (windowHeight / 2) + yOffset;

	WriteBuffer(x, y, text, color);
}

void Startscreen()
{
	ClearBuffer();// 또는 ClearBuffer() + FlipBuffer()
	FlipBuffer();

	WriteCenter("◆◆◆ Maze Escape ◆◆◆", -2, 14);       // 중앙보다 살짝 위
	WriteCenter("[ Press any key to start ]", 1, 7);

	FlipBuffer();

	_getch(); // 아무 키 누를 때까지 대기
}

void ClearScreen()		// 버퍼 사용을 모르던 시절 어떻게든 써보려고 한 함수
{
	COORD cursorPosition = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
