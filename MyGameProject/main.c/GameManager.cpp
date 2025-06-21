#include "GameManager.h"

void GameManager::Play()
{
	

	static bool isFirst = true;  // 최초 1회만 실행
	static bool isBufferInit = false;  // 최초 1회만 실행
	
	if (!isBufferInit)
	{
		InitBuffer();
		Startscreen();
		isBufferInit = true;
	}

	CheckStageClear(item);

	if (isFirst)
	{
		player.SetPos({ 1, 1 });
		mapboder.InitMap();
		currentMap = mapboder.GetMap(currentStageIndex);
		isFirst = false;
	}
	// 2. 플레이어가 맵 안에서만 움직이는지
	
	// 1. 맵 나오는지 확인 완료
	//LoadStage();
	ClearBuffer();     // 버퍼 초기화
	RenderMap();
	PlayerMove(player, currentMap, item);
	FlipBuffer();      // 최종적으로 현재 버퍼를 출력 화면으로 전환
	
	/*RenderMap();  */     // 맵, 플레이어, 아이템 다 WriteBuffer로 그려주기

}

void GameManager::RenderMap()
{
	stage.RenderMap(currentMap, player);
}

void GameManager::CountDown()
{
	for (int i = 3; i > 0; --i)
	{
		ClearBuffer();
		/*SetCurPosition(10, 10);
		std::cout << i;*/
		char countdown[10];
		sprintf_s(countdown, "%d", i);
		WriteBuffer(20, 10, countdown, 14);

		FlipBuffer();
		Sleep(700);
	}
	ClearBuffer();	// 다시 초기화
}

void GameManager::LoadStage()
{
	mapboder.InitMap();  // 전체 맵 초기화
	currentMap = mapboder.GetMap(currentStageIndex);
	player.SetPos({ 1, 1 });  // 초기 위치
	RenderMap();
}

void GameManager::CheckStageClear(Item& item)
{
	if (currentStageIndex == 0 && item.IsStage1Clear())
	{
		CountDown();
		item.Reset();
		currentStageIndex++;
		LoadStage();
	}
	else if (currentStageIndex == 1 && item.IsStage2Clear())
	{
		CountDown();
		ClearBuffer();
		WriteBuffer(10, 10, "게임 클리어!", 13);  // 분홍색 같은 색상
		FlipBuffer();
		/*SetCurPosition(10, 10);
		std::cout << "게임 클리어!";*/
		Sleep(2000);
		exit(0);  // 프로그램 종료
	}
}



void GameManager::ShowMap()
{
	player.SetPos({ 1, 1 });
	mapboder.InitMap();
	currentMap = mapboder.GetMap(currentStageIndex);
	RenderMap();
}


// 2. 플레이어가 맵안에서만 움직이도록 하기
void GameManager::PlayerMove(Player& player, vector<vector<int>>& map, Item& item)
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

		//  맵 벗어나지 않게 예외처리
		if (nextY < 0 || nextY >= map.size() || nextX < 0 || nextX >= map[0].size())
			return;

		//  벽이 아니라면 이동
		if (map[nextY][nextX] != TILE_WALL)
		{
			// 이전 위치 지우기
			WriteBuffer(curr.posX, curr.posY, " ", 0);

		/*	SetCurPosition(curr.posX, curr.posY);
			std::cout << "  ";*/

			player.Move(dx, dy);	// 위치 업데이트

			// 새 위치에 플레이어 출력
			Pos newPos = player.GetPos();
			/*SetCurPosition(newPos.posX, newPos.posY);
			std::cout << "◈";*/
			WriteBuffer(newPos.posX, newPos.posY, "◈", 15);  // 밝은 흰색

		}

		if (map[nextY][nextX] == TILE_ITEM1 || map[nextY][nextX] == TILE_ITEM2)
		{
			item.Collect(map[nextY][nextX]);       // 아이템 획득 처리
			map[nextY][nextX] = TILE_EMPTY;        // 먹은 자리 빈칸 처리
		}
	}
	Sleep(1);
	/*SetCurPosition(0, map.size() + 1);
	std::cout << "Heart: " << item.GetItem1Count() << " | Star: " << item.GetItem2Count() << "\n";*/
	//char status[50];
	//sprintf_s(status, "Heart: %d | Star: %d", item.GetItem1Count(), item.GetItem2Count());
	//WriteBuffer(0, map.size() + 1, status, 11);  // 밝은 하늘색 등으로 색 입혀도 됨

	// GameManager.cpp 내 함수 안에서
	int heartCount = item.GetItem1Count();
	int starCount = item.GetItem2Count();

	string heartBar = "Heart : ";
	for (int i = 0; i < heartCount; ++i) heartBar += "♥";

	string starBar = "Star  : ";
	for (int i = 0; i < starCount; ++i) starBar += "★";		// 스테이지 2에서만 나오게 하기 

	WriteBuffer(0, map.size() + 1, heartBar.c_str(), 4); // 빨간 하트
	WriteBuffer(0, map.size() + 2, starBar.c_str(), 6);  // 노란 별

}
