#include "Player.h"
#include "MapBoder.h"

extern int Map1 [세로][가로+1];		// 1번 스테이지의 크기
extern int Map2 [세로2][가로2+1];	// 2번 스테이지의 크기

Exit NextStage = { {29, 28 }, true };	// 스테이지2로 넘어가는 스테이지1 위치
Exit gameExit = { {29, 2}, true }; // 스테이지2 출구 좌표

// 기존 C버전 
//void MovePlayer(Player& player, Exit& exitptr)
//{
//	COORD stagePos = { 50,0 };
//	// 이전 위치 저장하기
//	player = player->playerPos.posX;
//	player->prevPosY = player->playerPos.posY;
//
//	// 현재 스테이지에 따라 사용할 맵 결정
//	int (*currentMap)[세로] = (player->CurrentStage == 1) ? Map1 : Map2;	// 삼항 연산자 사용
//
//	if (_kbhit())
//	{
//		SetCurPosition(player->playerPos.posX, player->playerPos.posY);	// 잔상이 남지 않게 한다.
//		printf("  ");
//		// 화살표 입력 인식 넣기
//
//		// 코드가 일치하면 true (C언어에서 입력을 사용할 때 사용한다.)
//		if (GetAsyncKeyState(VK_UP) & 0x8000) // 위
//		{
//			player->playerPos.posY--;
//			if (currentMap[player->playerPos.posY][player->playerPos.posX] == 1)
//			{
//				player->playerPos.posY++;
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 2) // 아이템 위치
//			{
//				player->heartCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 3) // 아이템 위치
//			{
//				player->starCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//
//		}
//
//		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래
//		{
//			player->playerPos.posY++;
//			if (currentMap[player->playerPos.posY][player->playerPos.posX] == 1)		// 플레이어가 벽을 뚫는 사태가 발생하면 안되기에
//				// 플레이어가 벽에 닿이면 다시 뒤로 밀려나는 것처럼 뚫지 못하게 설정하였다.
//			{
//				player->playerPos.posY--;
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 2) // 아이템 위치
//			{
//				player->heartCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 3) // 아이템 위치
//			{
//				player->starCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//
//		}
//
//		if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 좌
//		{
//			player->playerPos.posX--;
//			if (currentMap[player->playerPos.posY][player->playerPos.posX] == 1)	// x의 값 +2 (== 1칸이동)
//			{
//				player->playerPos.posX++;
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 2) // 아이템 위치
//			{
//				player->heartCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 3) // 아이템 위치
//			{
//				player->starCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//
//		}
//
//		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
//		{
//			player->playerPos.posX++;
//			if (currentMap[player->playerPos.posY][player->playerPos.posX] == 1)
//			{
//				player->playerPos.posX--;
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 2) // 아이템 위치
//			{
//				player->heartCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//			else if (currentMap[player->playerPos.posY][player->playerPos.posX] == 3) // 아이템 위치
//			{
//				player->starCount++;
//				currentMap[player->playerPos.posY][player->playerPos.posX] = 0; // 아이템 먹고 위치 초기화
//			}
//
//		}
//
//		// 2. 새 위치에 플레이어 그리기
//		SetCurPosition(player->playerPos.posX, player->playerPos.posY);
//		SetColor(0, 2);
//		printf("옷");
//		SetColor(0, 15);
//
//		// 3. 이전 위치 업데이트 (다음 프레임을 위해)
//		player->prevPosX = player->playerPos.posX;
//		player->prevPosY = player->playerPos.posY;
//
//		Sleep(100);
//
//	}
//
//	if (player->CurrentStage == 1)
//	{
//		if (player->heartCount >= 5)
//		{
//			currentMap[NextStage.exitPos.posY][NextStage.exitPos.posX] = 0;
//			SetCurPosition(30, 28);
//			printf("←");
//			SetCurPosition(40, 1);
//			printf("다음 스테이지로 이동합니다!\n");
//		}
//	}
//
//	if (player->playerPos.posX == 29 &&
//		player->playerPos.posY == 28)
//	{
//		// 스테이지 전환 로직
//		player->CurrentStage = 2;
//		player->playerPos.posX = 1;  // 스테이지 2 시작 좌표
//		player->playerPos.posY = 28;	// 스테이지 2 시작 좌표
//		player->starCount = 0;		 // 별 카운트 리셋
//		system("cls");
//		COORD stagePos = { 50,0 };
//		//ShowStage2(Stage2, stagePos);
//		ShowClearStage2();				// 맵 내부가 보이지 않는 함수
//		return; // 함수 즉시 종료
//	}
//	else if (player->CurrentStage == 2)
//	{
//		if (player->starCount >= 5)		// 별 5개 먹으면 출구 열리게
//		{
//			currentMap[gameExit.exitPos.posY][gameExit.exitPos.posX] = 0;
//			SetCurPosition(30, 2);
//			printf("←");
//			SetCurPosition(40, 2);
//			printf("출구가 활성화되었습니다!\n");
//		}
//		// 2. 출구 도착 감지
//		if (player->playerPos.posX == gameExit.exitPos.posX &&
//			player->playerPos.posY == gameExit.exitPos.posY)
//		{
//			system("cls");
//			SetCurPosition(25, 10);
//			//SetColor(0, 2);
//			printf("★★★★★ Game Clear ★★★★★");
//			exit(0); // 게임 완전 종료
//		}
//	}
//}

void Player::MovePlayer(Player& player, Pos& playerPos)
{
	COORD stagePos = { 50,0 };
	// 이전 위치 저장하기
	player.preX = player.playerPos.posX;
	player.preY = player.playerPos.posY;

	// 현재 스테이지에 따라 사용할 맵 결정
	int (*currentMap)[가로+1] = (player.CurrentStage == 1) ? Map1 : Map2;	// 삼항 연산자 사용

	if (_kbhit())
	{

		SetCurPosition(player.playerPos.posX, player.playerPos.posY);	// 잔상이 남지 않게 한다.
		printf("  ");
		// 화살표 입력 인식 넣기

		// 코드가 일치하면 true (C언어에서 입력을 사용할 때 사용한다.)
		if (GetAsyncKeyState(VK_UP) & 0x8000) // 위
		{
			// 나중에 함수로 묶어서 빼기)
			player.playerPos.posY--;
			//if (currentMap[player.playerPos.posY][player.playerPos.posX] == 1)
			//{
			//	player.playerPos.posY++;
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 2) // 아이템 위치
			//{
			//	player.heartCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 3) // 아이템 위치
			//{
			//	player.starCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}

		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 아래
		{
			player.playerPos.posY++;
			//if (currentMap[player.playerPos.posY][player.playerPos.posX] == 1)		// 플레이어가 벽을 뚫는 사태가 발생하면 안되기에
			//	// 플레이어가 벽에 닿이면 다시 뒤로 밀려나는 것처럼 뚫지 못하게 설정하였다.
			//{
			//	player.playerPos.posY--;
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 2) // 아이템 위치
			//{
			//	player.heartCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 3) // 아이템 위치
			//{
			//	player.starCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}

		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 좌
		{
			player.playerPos.posX--;
			//if (currentMap[player.playerPos.posY][player.playerPos.posX] == 1)	// x의 값 +2 (== 1칸이동)
			//{
			//	player.playerPos.posX++;
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 2) // 아이템 위치
			//{
			//	player.heartCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 3) // 아이템 위치
			//{
			//	player.starCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}

		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // 우
		{
			player.playerPos.posX++;
			//if (currentMap[player.playerPos.posY][player.playerPos.posX] == 1)
			//{
			//	player.playerPos.posX--;
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 2) // 아이템 위치
			//{
			//	player.heartCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}
			//else if (currentMap[player.playerPos.posY][player.playerPos.posX] == 3) // 아이템 위치
			//{
			//	player.starCount++;
			//	currentMap[player.playerPos.posY][player.playerPos.posX] = 0; // 아이템 먹고 위치 초기화
			//}

		}

		// 2. 새 위치에 플레이어 그리기
		//SetCurPosition(player.playerPos.posX, player.playerPos.posY);
		//SetColor(0, 2);
		//cout<<"옷";
		//SetColor(0, 15);

		//// 3. 이전 위치 업데이트 (다음 프레임을 위해)
		//player.preX = player.playerPos.posX;
		//player.preY = player.playerPos.posY;

		//Sleep(100);

	}
	
	// 밑의 코드는 GameManager에다 구현할 예정
	//if (player.CurrentStage == 1)
	//{
	//	if (player.heartCount >= 5)
	//	{
	//		currentMap[NextStage.exitPos.posY][NextStage.exitPos.posX] = 0;
	//		SetCurPosition(30, 28);
	//		printf("←");
	//		SetCurPosition(40, 1);
	//		printf("다음 스테이지로 이동합니다!\n");
	//	}
	//}

	//if (player.playerPos.posX == 29 &&
	//	player.playerPos.posY == 28)
	//{
	//	// 스테이지 전환 로직
	//	player.CurrentStage = 2;
	//	player.playerPos.posX = 1;  // 스테이지 2 시작 좌표
	//	player.playerPos.posY = 28;	// 스테이지 2 시작 좌표
	//	player.starCount = 0;		 // 별 카운트 리셋
	//	system("cls");
	//	COORD stagePos = { 50,0 };
	//	//ShowStage2(Stage2, stagePos);
	//	ShowClearStage2();				// 맵 내부가 보이지 않는 함수
	//	return; // 함수 즉시 종료
	//}
	//else if (player.CurrentStage == 2)
	//{
	//	if (player.starCount >= 5)		// 별 5개 먹으면 출구 열리게
	//	{
	//		currentMap[gameExit.exitPos.posY][gameExit.exitPos.posX] = 0;
	//		SetCurPosition(30, 2);
	//		printf("←");
	//		SetCurPosition(40, 2);
	//		printf("출구가 활성화되었습니다!\n");
	//	}
	//	// 2. 출구 도착 감지
	//	if (player.playerPos.posX == gameExit.exitPos.posX &&
	//		player.playerPos.posY == gameExit.exitPos.posY)
	//	{
	//		system("cls");
	//		SetCurPosition(25, 10);
	//		//SetColor(0, 2);
	//		printf("★★★★★ Game Clear ★★★★★");
	//		exit(0); // 게임 완전 종료
	//	}
	//}
}


//void Player::MovePlayer(Player& player, Pos& playerPos, const Exit& exitptr)
//{
//	// 플레이어가 움직여야함 
//	// 움직이는 것만 해야하니까 map을 가져와서 작동되는지 확인이 우선일거같음
//	player.Shape = "▲";
//}
