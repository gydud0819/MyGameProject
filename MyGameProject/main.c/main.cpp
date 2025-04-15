#include "MapBoder.h"
#include "Console.h"
#include "Player.h"


extern int Map1[가로][세로];	// 미로의 크기
extern int Map2[가로2][세로2];	// 미로의 크기

int main()
{
	COORD stagePos = { 50,0 };
	//ShowStage1(Stage1, stagePos);			// 미로 내부가 보이는 함수
	ShowClearStage1(Stage1, stagePos);			// 미로 내부가 보이지 않는 함수
	//ShowStage2();			// 두번째 스테이지 맵
	HideCursor();

	int playerX = 11;	// 플레이어의 시작 위치
	int playerY = 2;	// 플레이어의 시작 위치

	SetCurPosition(playerX, playerY);
	printf("옷");

	Player player;
	player.playerShape = "옷";
	player.playerPos.posX = 11;
	player.playerPos.posY = 2;
	player.mazeExit = false;
	player.heartCount = 0;
	player.starCount = 0;	// 2번째 스테이지 아이템 초기화
	player.CurrentStage = 1;

	Exit exit;
	exit.exitPos.posX = 29;
	exit.exitPos.posY = 2;
	exit.exit = false;

	SetCurPosition(player.playerPos.posX, player.playerPos.posY);
	SetColor(0, 2);
	printf("옷");
	SetColor(0, 15);
		
	while (true)
	{
		int prevX = player.playerPos.posX;
		int prevY = player.playerPos.posY;

		// ▼▼▼ 부분 화면 갱신 ▼▼▼
		if (prevX != player.playerPos.posX || prevY != player.playerPos.posY) 
		{
			SetCurPosition(prevX, prevY);
			printf(" "); // 이전 위치 지우기
			SetCurPosition(player.playerPos.posX, player.playerPos.posY);
			SetColor(0, 2);
			printf("옷");
			SetColor(0, 15);
		}
				
		MovePlayer(&player, &exit);

		Sleep(50);
		

	}
}