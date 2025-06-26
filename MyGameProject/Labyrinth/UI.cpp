#include "UI.h"

MenuOption ShowMenu()
{
	int selected = 0;
	const int menuCount = 4;

	const int menuYStart = 34;
	const int menuX = 58;  // 메뉴 텍스트가 나올 X좌표 == 하드코딩 같은데 그래도 어쩔 수 없음 콘솔창 기준 중앙정렬한 값이니까
	const int pointerX = menuX - 4;  // ▶ 포인터는 메뉴 왼쪽

	const char* menuTexts[menuCount] =
	{
		"[ 게임 시작 ]",
		"[ 게임 방법 ]",
		"[ 개발자의 편지 ]",
		"[ 게임 종료 ]"
	};


	while (true)
	{
		ClearBuffer();
		ShowTitle(); // ASCII 타이틀


		for (int i = 0; i < menuCount; ++i)
		{
			int y = menuYStart + i * 2;
			WriteBuffer(menuX, y, "                              ", 0); // 충분히 긴 공백으로 덮기

			int color = (i == selected) ? 15 : 8;
			WriteBuffer(menuX, y, menuTexts[i], color);  // 포인터 없이 강조만
		}

				FlipBuffer();

		int key = _getch();
		if (key == 224 || key == 0) key = _getch();		// 224, 75 == 방향키 아스키코드 

		if (key == 72) selected = (selected + menuCount - 1) % menuCount; // ↑
		else if (key == 80) selected = (selected + 1) % menuCount;        // ↓
		else if (key == 27); // 뒤로가기 esc
		else if (key == 13) break; // Enter
	}

	return static_cast<MenuOption>(selected);
}

void ShowTItle()
{
	ClearBuffer();		// 또는 ClearBuffer() + FlipBuffer()
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

	case MenuOption::Letter:
		Letter();		// 편지 내용
		ShowTItle();     // 다시 타이틀로 돌아오기
		return;

	case MenuOption::Exit:
		exit(0);         // 프로그램 종료
	}

	FlipBuffer();

}

void ShowTitle(int offsetY, int color)
{
	const char* title[] =
	{
		"     ##    ###   #####   ##  ##  #####   ####  ##  ##  ######  ##  ##    ",
		"     ##   ## ##  ##  ##  ##  ##  ##  ##   ##   ### ##    ##    ##  ##    ",
		"     ##   #####  #####    ####   #####    ##   ######    ##    ######    ",
		"     ##   ## ##  ##  ##    ##    ## ##    ##   ## ###    ##    ##  ##    ",
		"     #### ## ##  #####     ##    ##  ##  ####  ##  ##    ##    ##  ##    ",
	};


	int numLines = sizeof(title) / sizeof(title[0]);

	for (int i = 0; i < numLines; ++i)		// 전위로 사용한 이유 : 
	{
		WriteCenterAdjusted(title[i], -6 + i, 8, 4);  // y좌표를 위에서부터 점점 아래로, 색상은 8(회색)
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

	WriteCenter("    [     게임 방법     ]                ", -12, 15);

	WriteCenter("※   조작 방법 : 방향키  ← ↑ ↓ →         ", -8, 7);
	WriteCenter("※   어두운 내부를 기본으로 주어진 빛에 의지해야합니다.           ", -4, 7);
	WriteCenter("※   내부를 밝혀주는 아이템이 존재합니다.    ", 0, 7);
	//WriteCenter("※   아이템이 곧 열쇠입니다.                ", 2, 7);
	WriteCenter("※   무사 탈출을 기원합니다.                 ", 4, 7);

	WriteCenter("  [     Press any key to return to menu     ]", 10, 15);		// 거슬리네 
	//WriteCenter("    [     돌아가기      ]                ", 10, 15);

	FlipBuffer();
	_getch();
}

// 3 2 1 카운트 다운 원하는 수 만큼 늘려도됨 
void CountDown()
{
	for (int i = 3; i > 0; --i)
	{
		ClearBuffer();
		WriteBuffer(54, 30, "다음 스테이지로 넘어갑니다...", 8);  //  얘도 함수로 빼서 할까  아니야 하지말자 
		char countdown[10];			// 나중에 string으로 바꿔서 적용하기
		// 정수를 문자열로 변환해서 버퍼에 저장하는 함수 (버퍼 오버플로우 방지용으로 _s 사용)
		sprintf_s(countdown, "%d", i);	// 버퍼랑 관련된 함수로 이걸 써야 변환이 된다.
		WriteBuffer(/*35, 12*/71, 30, "   ", 14);  // 숫자 지울 공간 확보 -> 절반 해결 
		WriteBuffer(71, 30, countdown, 15);
		//ClearBuffer();
		FlipBuffer();



		//FlipBuffer();
		Sleep(600);		// 여기선 Sleep을 무조건 써야함 -> 시간 제어 해주는거 
	}
	ClearBuffer();	// 다시 초기화
}

void EndingTitle(int offsetY, int color)
{
	const char* endtitle[] =
	{
		"     ######   ##   ##   #######      #######   ##  ##  #######     ###                 ",
		"       ##     ##   ##   ##           ##        ### ##  ##    ##   #  ##                ",
		"       ##     #######   #####        #####     ######  ##    ##     ##                 ",
		"       ##     ##   ##   ##           ##        ## ###  ##    ##     #                  ",
		"       ##     ##   ##   #######      #######   ##  ##  #######                         ",
		"                                                                    #                  "
	};


	int numLines = sizeof(endtitle) / sizeof(endtitle[0]);

	for (int i = 0; i < numLines; ++i)
	{
		WriteCenterAdjusted(endtitle[i], -3 + i, 8, 6);  // y좌표를 위에서부터 점점 아래로, 색상은 8(회색)
	}
}

//void DrawItemUI(int offsetX, int offsetY, int mapHeight)
//{
//	// GameManager.cpp 내 함수 안에서
//	int heartCount = item.GetItem1Count();
//	int starCount = item.GetItem2Count();
//	int cloverCount = item.GetItem3Count();
//
//	string heart = "Heart : ";
//	for (int i = 0; i < heartCount; ++i) heart += "♥";
//
//	string star = "Star  : ";
//	for (int i = 0; i < starCount; ++i) star += "★";		// 스테이지 2에서만 나오게 하기 
//
//	string clover = "Clover : ";
//	for (int i = 0; i < cloverCount; ++i) clover += "♣";
//
//	int uiX = offsetX + currentMap[0].size() + 2; // 맵 오른쪽 옆에 출력 (두 칸 띄움)
//	int uiY = offsetY; // 맵 맨 위 기준
//
//	if (currentStageIndex == 0)
//	{
//		WriteBuffer(44, uiY + 32, heart.c_str(), 4); // 빨간 하트
//	}
//	else if (currentStageIndex == 1)
//	{
//		WriteBuffer(44, uiY + 32, star.c_str(), 14);  // 노란 별
//
//	}
//	else if (currentStageIndex == 2)			// 직사각형이니까 좌표수정은 맵 수정하고 나서 하기 
//	{
//		WriteBuffer(50, uiY + 18, clover.c_str(), 10);  // 클로버 
//
//	}
//}

void Letter()
{
	ClearBuffer();

	vector<string> letter =
	{
		"누구나 인생에서 한 번쯤은",
		"출구가 보이지 않는 미로를 걷습니다.",
		"  ",
		"이 게임은 단순한 탈출 게임이 아닙니다.",
		"빛이 없는 어둠 속에서",
		"‘나’를 찾아가고 ‘길’을 스스로 만들어 가는 여정입니다.",
		"",
		"랜턴은 주변을 밝히는 도구일 뿐",			// 랜턴은 해결방법 중 일부  이걸 단어로 어떻게 표현하지
		/*"자신의 눈으로 세상을 바라보게 하는 장치이고,",*/
		"나아갈 방향은 당신이 선택해야 합니다.",
		"",
		"이 짧은 미로 속에서",
		"조금이나마 자신을 마주할 수 있기를 바랍니다.",
		"",
		"디렉터 효 올림"
	};

	// 최대 길이 구하기
	int maxLen = 0;
	for (const auto& line : letter)
		if (line.size() > maxLen) maxLen = line.size();

	//int totalLines = letter.size();
	//int startY = (BufferHeight - totalLines) / 2;  // 화면 가운데 줄부터 시작
	// maxLen을 기준으로 화면 가운데 왼쪽 정렬 시작 위치 계산
	int offsetX = (BufferWidth - maxLen) / 2;
	int offsetY = (BufferHeight - letter.size()) / 2;

	for (int i = 0; i < letter.size(); ++i)
	{
		WriteBuffer(offsetX, offsetY + i, letter[i].c_str(), 7);  // 왼쪽 정렬!
	}

	//for (int i = 0; i < letter.size(); ++i)
	//{
	//	int offsetX = (BufferWidth - letter[i].size()) / 2;  // 각 줄마다 다르게
	//	WriteBuffer(offsetX, offsetY + i, letter[i].c_str(), 7);
	//}
	//for (int i = 0; i < letter.size(); ++i)
	//{
	//	// 가운데 정렬해서 출력
	//	int offsetX = (BufferWidth - letter[i].size()) / 2;
	//	WriteBuffer(offsetX, startY + i, letter[i].c_str(), 7);  // 흰색(7)
	//}

	FlipBuffer();  // 더블버퍼 갱신

	// 엔터 입력 대기
	while (true)
	{
		if (_kbhit() && _getch() == 13) break;  // Enter 누르면 종료
	}
}

