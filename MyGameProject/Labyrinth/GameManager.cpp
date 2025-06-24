#include "GameManager.h"

// GameManager.cpp가 모든걸 총괄하긴 하지만 너무 몰빵한 느낌이 듦
GameManager::~GameManager()
{

}

bool GameManager::Play()
{
	// 맵, 플레이어, 아이템 다 WriteBuffer로 그려주기

	static bool isFirst = true;			// 게임 시작할 때 딱 1번만 실행되게 설정		 여기도 gameManager.h에 private로 선언해서 빼줘도 될듯
	static bool isBufferInit = false;  // 버퍼 초기화도 딱 1번만 하게				   	 여기도 gameManager.h에 private로 선언해서 빼줘도 될듯
	if (!isBufferInit)
	{
		InitBuffer();		// 콘솔 버퍼 초기화 (더블 버퍼 구조 잡기)
		ShowTItle();		// 타이틀 화면 출력
		isBufferInit = true;
	}

	CheckStageClear(item);	// 아이템 조건 충족했는지 확인해서 다음 스테이지로 넘어갈 수 있게 처리

	if (isFirst)
	{
		//time.Start();
		player.SetPos({ 1, 1 });	// 플레이어 시작 위치 지정 (왼쪽 위) -> 나중에 랜덤으로 배치하는게 가능하면 할 예정
		mapboder.InitMap();			 // 맵 데이터 불러오기
		currentMap = mapboder.GetMap(currentStageIndex);		// 현재 스테이지 맵 가져오기
		stage.SetMap(currentMap);
		isFirst = false;			// 이후엔 다시 실행되지 않도록 false처리하기 
	}
	// 2. 플레이어가 맵 안에서만 움직이는지

	// 1. 맵 나오는지 확인 완료
	PlayerMove(player, item);	// 플레이어 이동 처리 + 아이템 먹기 처리
	Update();		   // 랜턴 아이템 처리하는 코드
	ClearBuffer();     // 출력 버퍼 비우기 (매 프레임 깔끔하게 만들기 위해서)
	RenderMap();		// 맵, 플레이어, 아이템 등 화면에 출력 -> 나한테 좀 중요함

	// 타이머 띄우기 == 초기화 안됨 
	//int offsetX = currentMap[0].size() * 2 + 4;  // 또는 BufferWidth - 25
	//int offsetY = 1;

	//time.DisplayPlayTime(/*BufferWidth - 25, 0*/ 80,20);  // 우측 상단에 표시
	FlipBuffer();      // 버퍼 교체 → 지금 그린 화면을 실제로 보여줌

	//Sleep(20);		// 임시 주석

	return true;
}

// 랜턴때문에 안돌아가니까 다시 해보기 
void GameManager::RenderMap()
{
	vector<vector<int>> map = stage.GetMap();

	if (map.empty()) return;

	int mapWidth = map[0].size();
	int mapHeight = map.size();

	int offsetX = ((BufferWidth / 2) - mapWidth) / 2; /*(BufferWidth - mapWidth * 2) / 2;*/
	int offsetY = (BufferHeight - mapHeight) / 2;


	stage.RenderMap(map, player, isRevealMap, offsetX, offsetY);

	DrawItemUI(offsetX, offsetY, mapHeight);
}



void GameManager::LoadStage()	// 맵 가져오기
{
	mapboder.InitMap();  // 전체 맵 초기화
	currentMap = mapboder.GetMap(currentStageIndex);
	stage.SetMap(currentMap);
	player.SetPos({ 1, 1 });  // 초기 위치 -> 나중에 랜덤으로 시도해보기 
	RenderMap();
}

//맵 내부 랜턴 아이템 처리하는 코드 == 이거도 아이템 클래스로 빼도 될거 같음 
void GameManager::Update()
{
	if (isRevealMap)
	{
		auto now = chrono::steady_clock::now();
		int elapsed = chrono::duration_cast<chrono::seconds>(now - revealStartTime).count();

		if (elapsed >= revealDuration)	// 공개한 시간보다 오버됐을때 
		{
			isRevealMap = false;		// 다시 어둡게 돌아간다

		}
	}
}

 //아이템 먹은거 확인하는 UI함수 == UI 헤더를 만들어서 따로 받아오던가 해야겠다 
void GameManager::DrawItemUI(int offsetX, int offsetY, int mapHeight)
{
	// GameManager.cpp 내 함수 안에서
	int heartCount = item.GetItem1Count();
	int starCount = item.GetItem2Count();
	int cloverCount = item.GetItem3Count();

	string heart = "Heart : ";
	for (int i = 0; i < heartCount; ++i) heart += "♥";

	string star = "Star  : ";
	for (int i = 0; i < starCount; ++i) star += "★";		// 스테이지 2에서만 나오게 하기 

	string clover = "Clover : ";
	for (int i = 0; i < cloverCount; ++i) clover += "♣";

	int uiX = offsetX + currentMap[0].size() + 2; // 맵 오른쪽 옆에 출력 (두 칸 띄움)
	int uiY = offsetY; // 맵 맨 위 기준

	if (currentStageIndex == 0)
	{
		WriteBuffer(45, uiY + 32, heart.c_str(), 4); // 빨간 하트
	}
	else if (currentStageIndex == 1)
	{
		WriteBuffer(45, uiY + 32, star.c_str(), 6);  // 노란 별

	}
	else if (currentStageIndex == 2)			// 직사각형이니까 좌표수정은 맵 수정하고 나서 하기 
	{
		WriteBuffer(45, uiY + 32, clover.c_str(), 13);  // 클로버 

	}


}

void GameManager::CheckStageClear(Item& item)
{
	// 이것도 for문 돌려서 해결할 수있을 거 같으니 일단 임시로 냅두기 
	if (currentStageIndex == 0 && item.IsStage1Clear())
	{
		CountDown();
		ClearBuffer();
		FlipBuffer();
		Sleep(1000);  // 잠깐 정지

		item.Reset();
		currentStageIndex++;

		LoadStage();
	}
	else if (currentStageIndex == 1 && item.IsStage2Clear())
	{
		CountDown();
		ClearBuffer();
		//WriteBuffer(25, 10, "다음 스테이지로 넘어갑니다...", 11);
		FlipBuffer();
		Sleep(1000);  // 잠깐 정지

		item.Reset();
		currentStageIndex++;
		LoadStage();
	}
	else if (currentStageIndex == 2 && item.IsStage3Clear())
	{
		//CountDown();
		ClearBuffer();
		WriteBuffer(30, 20, "escape¿", 7);  // 분홍색 같은 색상
		FlipBuffer();
		Sleep(2000);
		exit(0);  // 프로그램 종료
	}
}

// todo: 버퍼 구조때문인지 콘솔창 크게하면 잔상이 많이남음 
//void GameManager::CountDown()
//{
//	for (int i = 3; i > 0; --i)
//	{
//		ClearBuffer();
//		WriteBuffer(45, 30, "다음 스테이지로 넘어갑니다...", 8);  // 잔상 해결해야하는데 
//		char countdown[10];			// 나중에 string으로 바꿔서 적용하기
//		// 정수를 문자열로 변환해서 버퍼에 저장하는 함수 (버퍼 오버플로우 방지용으로 _s 사용)
//		sprintf_s(countdown, "%d", i);	// 버퍼랑 관련된 함수로 이걸 써야 변환이 된다.
//		WriteBuffer(/*35, 12*/61, 30, "   ", 14);  // 숫자 지울 공간 확보 -> 절반 해결 
//		WriteBuffer(61, 30, countdown, 15);
//		//ClearBuffer();
//		FlipBuffer();
//
//
//
//		//FlipBuffer();
//		Sleep(1000);		// 여기선 Sleep을 무조건 써야함 -> 시간 제어 해주는거 
//	}
//	ClearBuffer();	// 다시 초기화
//}

void GameManager::ShowMap()
{

	player.SetPos({ 1, 1 });
	mapboder.InitMap();
	currentMap = mapboder.GetMap(currentStageIndex);
	RenderMap();
}


// 2. 플레이어가 맵안에서만 움직이도록 하기
void GameManager::PlayerMove(Player& player, /*vector<vector<int>>& map,*/ Item& item)
{
	vector<vector<int>>& map = stage.GetMutableMap();
	if (_kbhit())
	{

		int dx = 0, dy = 0;		// 임시 좌표
		//switch (_getch())
		//{
		//case 72: dy = -1; break;  // ↑ 방향키 모양 ▲ ▼ ◀	▶ 로 누를때마다 할 예정 
		//case 80: dy = 1; break;   // ↓ 
		//case 75: dx = -1; break;  // ←
		//case 77: dx = 1; break;   // →
		//}

		switch (_getch())
		{
		case 72: dy = -1; player.SetDirection(Direction::Up); break;	// ▲
		case 80: dy = 1;  player.SetDirection(Direction::Down); break;	// ▼
		case 75: dx = -1; player.SetDirection(Direction::Left); break;
		case 77: dx = 1;  player.SetDirection(Direction::Right); break;
		}


		Pos curr = player.GetPos();		// 플레이어가 움직이는거 

		int nextX = curr.posX + dx;
		int nextY = curr.posY + dy;

		//  맵 벗어나지 않게 예외처리
		if (nextY < 0 || nextY >= map.size() || nextX < 0 || nextX >= map[0].size())
			return;

		//  벽이 아니라면 이동
		if (map[nextY][nextX] != TILE_WALL)
		{
			// 이전 위치 지우기
			//WriteBuffer(curr.posX, curr.posY, " ", 0);

			player.Move(dx, dy);	// 위치 업데이트

			// 새 위치에 플레이어 출력
			Pos newPos = player.GetPos();
			//WriteBuffer(newPos.posX, newPos.posY, "◈", 15);  // 밝은 흰색
		}

		if (map[nextY][nextX] == TILE_ITEM1 || map[nextY][nextX] == TILE_ITEM2 || map[nextY][nextX] == TILE_ITEM4)
		{
			item.Collect(map[nextY][nextX]);       // 아이템 획득 처리
			map[nextY][nextX] = TILE_EMPTY;        // 먹은 자리 빈칸 처리
		}

		// 랜턴 처리 코드
		if (map[nextY][nextX] == TILE_ITEM3)
		{
			isRevealMap = true;
			revealStartTime = chrono::steady_clock::now();	// 현재 시간을 가져오는 함수 근데 왜 안돼 
			revealDuration = rand() % 3 + 3;  // 3~5초 == 5초간 맵 내부가 활성화된다는 멘트 추가하고 다시꺼질때 사라지게 하기 
			map[nextY][nextX] = TILE_EMPTY;		// 먹고나서 빈칸 초기화 

		}

	}
}