#include "UI.h"

MenuOption ShowMenu()
{
	int selected = 0;
	const int menuCount = 3;

	const int menuYStart = 42;
	const int menuX = 58;  // 메뉴 텍스트가 나올 X좌표
	const int pointerX = menuX - 3;  // ▶ 포인터는 메뉴 왼쪽

	const char* menuTexts[menuCount] = 
	{
		"[ Game Start ]",
		"[ Game  Rule ]",
		"[    Exit    ]"
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
				WriteBuffer(pointerX, y, "☞", 15);  // ← 화살표는 왼쪽에  // 화살표 표시안하고 감싸야겠다.
				//WriteBuffer(pointerX, y, "┎───────┓", 15);  // ← 화살표는 왼쪽에  // 화살표 표시안하고 감싸야겠다.
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
		"    ##        ####    #####    ##  ##   #####     ####    ##  ##   ######   ##  ##      #   ",  // #
		"    ##       ##  ##   ##  ##   ##  ##   ##  ##     ##     ### ##     ##     ##  ##           ",  //
		"    ##       ######   #####     ####    #####      ##     ######     ##     ######      #   ",  // #
		"    ##       ##  ##   ##  ##     ##     ## ##      ##     ## ###     ##     ##  ##       #  ",  // ##
		"    #####    ##  ##   #####      ##     ##  ##    ####    ##  ##     ##     ##  ##        # ",  // ###
		"                                                                                      ###  "   // ###
	};

	int numLines = sizeof(title) / sizeof(title[0]);

	for (int i = 0; i < numLines; ++i)
	{
		WriteCenter(title[i], 2 + i, 8);  // y좌표를 위에서부터 점점 아래로, 색상은 8(회색)
	}
}

#pragma region 콘솔 색상 정리
/*
* 0 = 블랙
* 1 = 딥블루
* 2 = 그린
* 3 = 라이트 블루	// 청록색
* 4 = 레드
* 5 = 자주색
* 6 = 머스타드(이게 갈색?)
* 7 = 회색같은 화이트
* 8 = 다크 그레이
* 9 = 밝은 블루
* 10 = 밝은 초록
* 11 = 민트와 하늘색 그 어딘가
* 12 = 덜 레드
* 13 = 밝은 보라(연보라는 아님)
* 14 = 옐로우
* 15 = 화이트
*/
#pragma endregion



void ShowGameRule()
{
	ClearBuffer();

	WriteCenter("    [     게임 방법     ]                ", -4, 15);

	WriteCenter("※   조작 방법 : 방향키  ← ↑ ↓ →         ", 2, 7);
	WriteCenter("※   미로를 탐험하며 아이템을 모으세요.      ", 0, 7);
	WriteCenter("※   내부를 밝혀주는 아이템이 존재합니다.    ", 4, 7);
	WriteCenter("※   아이템이 곧 열쇠입니다.                ", 6, 7);
	WriteCenter("※   무사 탈출을 기원합니다.                 ", 8, 7);

	WriteCenter("  [     Press any key to return to menu     ]", 14, 7);
	//WriteCenter("    [     돌아가기      ]                ", 14, 7);

	FlipBuffer();
	_getch();
}

// 3 2 1 카운트 다운 원하는 수 만큼 늘려도됨 
void CountDown()
{
	for (int i = 5; i > 0; --i)
	{
		ClearBuffer();
		WriteBuffer(54, 30, "다음 스테이지로 넘어갑니다...", 8);  //  
		char countdown[10];			// 나중에 string으로 바꿔서 적용하기
		// 정수를 문자열로 변환해서 버퍼에 저장하는 함수 (버퍼 오버플로우 방지용으로 _s 사용)
		sprintf_s(countdown, "%d", i);	// 버퍼랑 관련된 함수로 이걸 써야 변환이 된다.
		WriteBuffer(/*35, 12*/71, 30, "   ", 14);  // 숫자 지울 공간 확보 -> 절반 해결 
		WriteBuffer(71, 30, countdown, 15);
		//ClearBuffer();
		FlipBuffer();



		//FlipBuffer();
		Sleep(1000);		// 여기선 Sleep을 무조건 써야함 -> 시간 제어 해주는거 
	}
	ClearBuffer();	// 다시 초기화
}

void EndingTitle(int offsetY, int color)
{
	const char* endtitle[] =
	{
		"    ##        ####    #####    ##  ##   #####     ####    ##  ##   ######   ##  ##      #   ",  // #
		"    ##       ##  ##   ##  ##   ##  ##   ##  ##     ##     ### ##     ##     ##  ##           ",  //
		"    ##       ######   #####     ####    #####      ##     ######     ##     ######      #   ",  // #
		"    ##       ##  ##   ##  ##     ##     ## ##      ##     ## ###     ##     ##  ##       #  ",  // ##
		"    #####    ##  ##   #####      ##     ##  ##    ####    ##  ##     ##     ##  ##        # ",  // ###
		"                                                                                      ###  "   // ###
	};

	int numLines = sizeof(endtitle) / sizeof(endtitle[0]);

	for (int i = 0; i < numLines; ++i)
	{
		WriteCenter(endtitle[i], 2 + i, 8);  // y좌표를 위에서부터 점점 아래로, 색상은 8(회색)
	}
	//WriteBuffer(30, 20, "escape¿", 7);  // 분홍색 같은 색상		==> UI로빼서 크게 해야겠다 
}
