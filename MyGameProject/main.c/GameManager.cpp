#include "GameManager.h"

void GameManager::Play()
{
	// 맵, 플레이어, 아이템 다 WriteBuffer로 그려주기

	static bool isFirst = true;			// 게임 시작할 때 딱 1번만 실행되게 설정
	static bool isBufferInit = false;  // 버퍼 초기화도 딱 1번만 하게
	if (!isBufferInit)
	{
		InitBuffer();		// 콘솔 버퍼 초기화 (더블 버퍼 구조 잡기)
		Startscreen();		// 타이틀 화면 출력
		isBufferInit = true;
	}

	CheckStageClear(item);	// 아이템 조건 충족했는지 확인해서 다음 스테이지로 넘어갈 수 있게 처리

	if (isFirst)
	{
		player.SetPos({ 1, 1 });	// 플레이어 시작 위치 지정 (왼쪽 위) -> 나중에 랜덤으로 배치하는게 가능하면 할 예정
		mapboder.InitMap();			 // 맵 데이터 불러오기
		currentMap = mapboder.GetMap(currentStageIndex);		// 현재 스테이지 맵 가져오기
		isFirst = false;			// 이후엔 다시 실행되지 않도록 false처리하기 
	}
	// 2. 플레이어가 맵 안에서만 움직이는지
	
	// 1. 맵 나오는지 확인 완료
	PlayerMove(player, currentMap, item);	// 플레이어 이동 처리 + 아이템 먹기 처리
	Update();
	ClearBuffer();     // 출력 버퍼 비우기 (매 프레임 깔끔하게 만들기 위해서)
	RenderMap();		// 맵, 플레이어, 아이템 등 화면에 출력 -> 나한테 좀 중요함
	FlipBuffer();      // 버퍼 교체 → 지금 그린 화면을 실제로 보여줌
	
	     

}

// 랜턴때문에 안돌아가니까 다시 해보기 
//void GameManager::RenderMap()
//{
//	stage.RenderMap(currentMap, player, isRevealMap);
//}

void GameManager::CountDown()	// 스테이지 넘어갈때 카운트다운 나오는 함수 진짜 구현하기 ㅈㄴ힘들었다ㅠㅠ
{
	for (int i = 3; i > 0; --i)
	{
		ClearBuffer();
	
		char countdown[10];			// 나중에 string으로 바꿔서 적용하기
		// 정수를 문자열로 변환해서 버퍼에 저장하는 함수 (버퍼 오버플로우 방지용으로 _s 사용)
		sprintf_s(countdown, "%d", i);	// 버퍼랑 관련된 함수로 이걸 써야 변환이 된다.
		WriteBuffer(20, 10, countdown, 14);

		FlipBuffer();
		Sleep(1000);
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

// 맵 내부 랜턴 아이템 처리하는 코드 오류 겁나 나니까 내일 다시 손보기 
//void GameManager::Update()
//{
//	if (isRevealMap)
//	{
//		auto now = chrono::steady_clock::now();
//		int elapsed = chrono::duration_cast<chrono::seconds>(now - revealStartTime).count();
//
//		if (elapsed >= revealDuration)
//		{
//			isRevealMap = false;
//			//cout << "랜턴 효과 종료" << endl;
//		}
//	}
//}

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
		//CountDown();
		//ClearBuffer();
		//WriteBuffer(10, 10, "게임 클리어!", 13);  // 분홍색 같은 색상
		//FlipBuffer();
		///*SetCurPosition(10, 10);
		//std::cout << "게임 클리어!";*/
		//Sleep(2000);
		//exit(0);  // 프로그램 종료
		CountDown();
		item.Reset();
		currentStageIndex++;
		LoadStage();
	}
	else if (currentStageIndex == 2 && item.IsStage3Clear())
	{
		CountDown();
		ClearBuffer();
		WriteBuffer(10, 10, "게임 클리어", 13);  // 분홍색 같은 색상
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

		//  맵 벗어나지 않게 예외처리
		if (nextY < 0 || nextY >= map.size() || nextX < 0 || nextX >= map[0].size())
			return;

		//  벽이 아니라면 이동
		if (map[nextY][nextX] != TILE_WALL)
		{
			// 이전 위치 지우기
			WriteBuffer(curr.posX, curr.posY, " ", 0);

			player.Move(dx, dy);	// 위치 업데이트

			// 새 위치에 플레이어 출력
			Pos newPos = player.GetPos();
			WriteBuffer(newPos.posX, newPos.posY, "◈", 15);  // 밝은 흰색

		}

		if (map[nextY][nextX] == TILE_ITEM1 || map[nextY][nextX] == TILE_ITEM2 || map[nextY][nextX] == TILE_ITEM4)
		{
			item.Collect(map[nextY][nextX]);       // 아이템 획득 처리
			map[nextY][nextX] = TILE_EMPTY;        // 먹은 자리 빈칸 처리
		}

		// 랜턴 처리 코드 == 안돌아감 다시 손 보기 
		//if (map[nextY][nextX] == TILE_ITEM3)
		//{
		//	isRevealMap = true;
		//	revealStartTime = chrono::steady_clock::now();
		//	revealDuration = rand() % 3 + 3;  // 3~5초 사이
		//	map[nextY][nextX] = TILE_EMPTY;

		//	//cout << "🌟 랜턴 발동! " << revealDuration << "초간 밝아집니다!" << endl;
		//}
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

	string heart = "Heart : ";
	for (int i = 0; i < heartCount; ++i) heart += "♥";

	string star = "Star  : ";
	for (int i = 0; i < starCount; ++i) star += "★";		// 스테이지 2에서만 나오게 하기 

	WriteBuffer(0, map.size() + 1, heart.c_str(), 4); // 빨간 하트
	WriteBuffer(0, map.size() + 2, star.c_str(), 6);  // 노란 별

}
