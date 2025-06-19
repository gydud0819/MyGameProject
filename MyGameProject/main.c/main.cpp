#include "MapBoder.h"
#include "Console.h"
#include "Player.h"


extern int Map1[세로][가로 + 1];	// 미로의 크기 exturn 붙여주기 
extern int Map2[세로2][가로2 + 1];	// 미로의 크기

int main()
{

	MapBoder map1;
	map1.InitMap();
	map1.ShowStage1();
	//map1.ShowClearStage1();

	// 플레이어 테스트 
	//Player player({ 12,1 });  // 시작 위치
	//while (true)
	//{
	//	


	//	if (_kbhit())
	//	{
	//		int dx = 0, dy = 0;		// 임시 좌표
	//		switch (_getch())
	//		{
	//		case 72: dy = -1; break;  // ↑
	//		case 80: dy = 1; break;   // ↓
	//		case 75: dx = -1; break;  // ←
	//		case 77: dx = 1; break;   // →
	//		}

	//		// 1. 현재 위치 저장
	//		int prevX = player.GetPos().posX;
	//		int prevY = player.GetPos().posY;

	//		player.Move(dx, dy);  // 이동

	//		// 기존 위치 지움
	//		SetCurPosition(prevX, prevY);
	//		cout << "  ";


	//		SetCurPosition(player.GetPos().posX, player.GetPos().posY);
	//		cout << "옷";
	//	}

	//	Sleep(50);
	//}




	//COORD stagePos = { 50,0 };
	////ShowStage1(Stage1, stagePos);			// 미로 내부가 보이는 함수
	//ShowClearStage1(*Stage1, stagePos);			// 미로 내부가 보이지 않는 함수
	////ShowStage2();			// 두번째 스테이지 맵
	//HideCursor();

	//int playerX = 11;	// 플레이어의 시작 위치
	//int playerY = 2;	// 플레이어의 시작 위치

	//SetCurPosition(playerX, playerY);
	//printf("옷");

	//Player player;
	//player.playerShape = "옷";
	//player.playerPos.posX = 11;
	//player.playerPos.posY = 2;
	//player.mazeExit = false;
	//player.heartCount = 0;
	//player.starCount = 0;	// 2번째 스테이지 아이템 초기화
	//player.CurrentStage = 1;

	//Exit exit;
	//exit.exitPos.posX = 29;
	//exit.exitPos.posY = 2;
	//exit.exit = false;

	//SetCurPosition(player.playerPos.posX, player.playerPos.posY);
	//SetColor(0, 2);
	//printf("옷");
	//SetColor(0, 15);
	//	
	//while (true)
	//{
	//	int prevX = player.playerPos.posX;
	//	int prevY = player.playerPos.posY;

	//	// 부분 화면 갱신 
	//	if (prevX != player.playerPos.posX || prevY != player.playerPos.posY) 
	//	{
	//		SetCurPosition(prevX, prevY);
	//		printf(" "); // 이전 위치 지우기
	//		SetCurPosition(player.playerPos.posX, player.playerPos.posY);
	//		SetColor(0, 2);
	//		printf("옷");
	//		SetColor(0, 15);
	//	}
	//			
	//	MovePlayer(&player, &exit);

	//	Sleep(50);
	//	

	//}
}