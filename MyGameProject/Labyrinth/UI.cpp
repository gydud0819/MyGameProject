#include "UI.h"

MenuOption ShowMenu()
{
	int selected = 0;
	const int menuCount = 3;

	const int menuYStart = 12;
	const int menuX = 50;  // 메뉴 텍스트가 나올 X좌표
	const int pointerX = menuX - 4;  // ▶ 포인터는 메뉴 왼쪽

	const char* menuTexts[menuCount] = 
	{
		"[ Game Start ]",
		"[ Game Rule  ]",
		"[ Exit       ]"
	};

	while (true)
	{
		ClearBuffer();
		ShowTitle(); // ASCII 타이틀

		for (int i = 0; i < menuCount; ++i)
		{
			int y = menuYStart + i * 2;

			WriteBuffer(menuX, y, menuTexts[i], 7);

			if (i == selected)
				WriteBuffer(pointerX, y, "▶ ", 15);  // ← 화살표는 왼쪽에
		}

	
		FlipBuffer();

		int key = _getch();
		if (key == 224 || key == 0) key = _getch();

		if (key == 72) selected = (selected + menuCount - 1) % menuCount; // ↑
		else if (key == 80) selected = (selected + 1) % menuCount;        // ↓
		else if (key == 13) break; // Enter
	}

	return static_cast<MenuOption>(selected);
}

void ShowTItle()
{
	ClearBuffer();// 또는 ClearBuffer() + FlipBuffer()
	FlipBuffer();

	ShowTitle();
	MenuOption option = ShowMenu();
	//ShowMenu();

	switch (option)
	{
	case MenuOption::Start:
		// 아무 처리도 안 하면 바로 게임 진행 (Play()로 연결됨)
		break;

	case MenuOption::Rule:
		ShowGameRule();  // 규칙 출력 함수
		ShowTItle();     // 다시 타이틀로 돌아오기
		return;

	case MenuOption::Exit:
		exit(0);         // 프로그램 종료
	}
	
	FlipBuffer();

	//_getch(); // 아무 키 누를 때까지 대기
}

void ShowTitle(int offsetY, int color)
{
	 //ASCII 타이틀 줄별로 선언

	const char* title[] =
	{
		"   ##        ####    #####    ##  ##   #####     ####    ##  ##   ######   ##  ##      #   ",  // #
		"   ##       ##  ##   ##  ##   ##  ##   ##  ##     ##     ### ##     ##     ##  ##           ",  //
		"   ##       ######   #####     ####    #####      ##     ######     ##     ######      #   ",  // #
		"   ##       ##  ##   ##  ##     ##     ## ##      ##     ## ###     ##     ##  ##       #  ",  // ##
		"   #####    ##  ##   #####      ##     ##  ##    ####    ##  ##     ##     ##  ##        # ",  // ###
		"                                                                                      ###  "   // ###
	};

	int numLines = sizeof(title) / sizeof(title[0]);

	for (int i = 0; i < numLines; ++i)
	{
		WriteCenter(title[i], -8 + i, 8);  // y좌표를 위에서부터 점점 아래로, 색상은 8(회색)
	}

	//WriteCenter("◆◆◆ Labyrinth¿ ◆◆◆", /*-2, 14*/ -10, 14);       // 중앙보다 살짝 위 -> 임시 타이틀
	//WriteCenter("[        게임시작        ]", 12, 7);
	//WriteCenter("[        게임설명        ]", 14, 7);
	//WriteCenter("[        게임종료        ]", 16, 7);
	//WriteCenter("[        Game Start      ]", 12, 7);		// 오른쪽으로 좀만 더 가면될거같은데 
	//WriteCenter("[        Game Rule       ]", 14, 7);
	//WriteCenter("[          Exit          ]", 16, 7);
	//WriteCenter("[ Press any key to start ]", 18, 7);
}

void ShowGameRule()
{
	ClearBuffer();

	WriteCenter("● 미로를 탐험하며 모든 아이템을 모으세요.", 10, 11);
	WriteCenter("● 방향키로 이동하고, 하트를 먼저 먹어야 합니다.", 12, 11);
	WriteCenter("● 총 3개의 스테이지를 클리어하면 탈출 성공!", 14, 11);
	WriteCenter("[ Press any key to return to menu ]", 18, 7);

	FlipBuffer();
	_getch();
}


void CountDown()
{
	for (int i = 3; i > 0; --i)
	{
		ClearBuffer();
		WriteBuffer(45, 30, "다음 스테이지로 넘어갑니다...", 8);  // 잔상 해결해야하는데 
		char countdown[10];			// 나중에 string으로 바꿔서 적용하기
		// 정수를 문자열로 변환해서 버퍼에 저장하는 함수 (버퍼 오버플로우 방지용으로 _s 사용)
		sprintf_s(countdown, "%d", i);	// 버퍼랑 관련된 함수로 이걸 써야 변환이 된다.
		WriteBuffer(/*35, 12*/61, 30, "   ", 14);  // 숫자 지울 공간 확보 -> 절반 해결 
		WriteBuffer(61, 30, countdown, 15);
		//ClearBuffer();
		FlipBuffer();



		//FlipBuffer();
		Sleep(1000);		// 여기선 Sleep을 무조건 써야함 -> 시간 제어 해주는거 
	}
	ClearBuffer();	// 다시 초기화
}
