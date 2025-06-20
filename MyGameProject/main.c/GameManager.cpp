#include "GameManager.h"

void GameManager::Play()
{

	ShowMap();	// 맵 불러오기 
	//PlayerMove();	// 플레이어움직이게 하기

	// 3. 제일 중요한 작업 맵 안에서 움직이게 하기
}

void GameManager::ShowMap()
{
	// 1. 맵 먼저 불러오기 -> 나온당 히히
	stage.InitMap();
	stage.ShowClearStage1();
}


// 2. 
void GameManager::PlayerMove(Player& player, Stage& stage)
{
	if (_kbhit())
	{ 

		int dx = 0, dy = 0;		// 임시 좌표
		switch (_getch())
		{
		case 72: dy = -1; break;  // ↑
		case 80: dy = 1; break;   // ↓
		case 75: dx = -1; break;  // ←
		case 77: dx = 1; break;   // →
		}

		Pos curr = player.GetPos();		// 플레이어가 움직이는거 

		// player충돌처리를 하려면 직접적인 인자가 필요한데 인자를 만들어야하나? 

		int nextX = curr.posX + dx;
		int nextY = curr.posY + dy;

		// player랑 map이랑 위치가 서로 1일때 제자리인거처럼 해야하니까
		// 맵을 불러와야하나? 불러왔는데? 대가리굴려라 

		if (player[nextX][nextY]== TILE_WALL)
		{
			player.Move(dx, dy);  // 이동
		}
		else if (player[nextX][nextY] == TILE_ITEM1)
		{
			// 아이템을 먹고 초기화 그럼 아이템도 구현해야하네? tq 
		}

		// 기존 위치 지움
		/*SetCurPosition(prevX, prevY);
		cout << "  ";


		SetCurPosition(player.GetPos().posX, player.GetPos().posY);
		cout << "◈";*/

	}

	Sleep(50);
}
