#include "GameManager.h"

bool GameManager::isFirst = true;			// 게임 시작할 때 딱 1번만 실행되게 설정	
bool GameManager::isBufferInit = false;		// 버퍼 초기화도 딱 1번만 하게		

GameManager::~GameManager()
{
	 
}

bool GameManager::Play()	// 플레이 흐름을 관여하는 함수 <= 얘가 핵심 메인
{
	ResizeConsole();	// 콘솔창 안찌그러지게 제어해주는 함수
	
	// 맵, 플레이어, 아이템 다 WriteBuffer로 그려주기
	if (!isBufferInit)
	{
		InitBuffer();		// 콘솔 버퍼 초기화 (더블 버퍼 구조 잡기)
		ShowTItle();		// 타이틀 화면 출력
		isBufferInit = true;
	}

	//CheckStageClear(item);		// 아이템 조건 충족했는지 확인해서 다음 스테이지로 넘어갈 수 있게 처리, 원래 여기있었음 

	if (isFirst)
	{
		time.Start();
		player.SetPos({ 1, 1 });									// 플레이어 시작 위치 지정 (왼쪽 위) -> 나중에 랜덤으로 배치하는게 가능하면 할 예정
		mapboder.InitMap();											// 맵 데이터 불러오기
		currentMap = mapboder.GetMap(currentStageIndex);			// 현재 스테이지 맵 가져오기
		stage.SetMap(currentMap);
		isFirst = false;											// 이후엔 다시 실행되지 않도록 false처리하기 
	}

	CheckStageClear(item);											// 여기잇어도 돌아가는이유가 머지 
	PlayerMove(player, item);										// 플레이어 이동 처리 + 아이템 먹기 처리
	Update();														// 랜턴 아이템 처리하는 코드
	ClearBuffer();													// 출력 버퍼 비우기 (매 프레임 깔끔하게 만들기 위해서)
	time.DisplayPlayTime(32, 14);									// 좌측 상단에 표시
	RenderMap();													// 맵, 플레이어, 아이템 등 화면에 출력 -> 나한테 좀 중요함

	FlipBuffer();													// 버퍼 교체 → 지금 그린 화면을 실제로 보여줌
	
	return true;
}

void GameManager::RenderMap()
{
	vector<vector<int>> map = stage.GetMap();

	if (map.empty()) return;

	int mapWidth = map[0].size(); 
	int mapHeight = map.size(); 

	int offsetX = ((BufferWidth / 2) - mapWidth) / 2; 
	int offsetY = (BufferHeight - mapHeight) / 2; 

	stage.RenderMap(map, player, isRevealMap, offsetX, offsetY);

	DrawItemUI(offsetX, offsetY, mapHeight);
}


void GameManager::LoadStage()	// 맵 가져오기
{
	mapboder.InitMap();  // 전체 맵 초기화
	currentMap = mapboder.GetMap(currentStageIndex);
	stage.SetMap(currentMap);
	player.SetPos({ 1, 1 });  // 초기 위치 -> 나중에 랜덤으로 시도해보기 -> 아니지 랜덤으로 돌릴려면 맵 크기, 맵 내부 벽 다 계산해야하는데 발표 이후에 할 수 있으면 해보기 
	RenderMap();
}

//맵 내부 랜턴 아이템 처리하는 코드
void GameManager::Update()
{
	if (isRevealMap)
	{
		auto now = chrono::steady_clock::now();
		int elapsed = chrono::duration_cast<chrono::seconds>(now - revealStartTime).count();

		if (elapsed >= revealDuration)	// 공개한 시간보다 오버됐을 때 
		{
			isRevealMap = false;		// 다시 어둡게 돌아간다

		}
	}
}

 //아이템 먹은거 확인하는 UI == UI.h로 분리 못한 이유 
void GameManager::DrawItemUI(int offsetX, int offsetY, int mapHeight)
{
	// GameManager.cpp 내 함수 안에서
	int heartCount = item.GetItem1Count();
	int starCount = item.GetItem2Count();
	int cloverCount = item.GetItem3Count();
	int AllItemCount = item.IsStage4Clear();

	string heart = "Key : ";
	for (int i = 0; i < heartCount; ++i) heart += "♥";

	string star = "Key : ";
	for (int i = 0; i < starCount; ++i) star += "★";		// 스테이지 2에서만 나오게 하기 

	string clover = "Key : ";
	for (int i = 0; i < cloverCount; ++i) clover += "♣";

	int uiX = offsetX + currentMap[0].size() + 2; // 맵 오른쪽 옆에 출력 (두 칸 띄움)
	int uiY = offsetY; // 맵 맨 위 기준

	if (currentStageIndex == 0)
	{
		WriteBuffer(45, uiY + 32, heart.c_str(), 4); // 빨간 하트
	}
	else if (currentStageIndex == 1)
	{
		WriteBuffer(45, uiY + 32, star.c_str(), 14);  // 노란 별

	}
	else if (currentStageIndex == 2)			// 직사각형이니까 좌표수정은 맵 수정하고 나서 하기 
	{
		WriteBuffer(50, uiY + 18, clover.c_str(), 10);  // 클로버 

	}
	else if (currentStageIndex == 3)
	{
		WriteBuffer(45, uiY + 24, heart.c_str(), 4);		// 이거 안될거같은ㄷ 
		WriteBuffer(45, uiY + 26, star.c_str(), 14);		// 이거 안될거같은ㄷ 
		WriteBuffer(45, uiY + 28, clover.c_str(), 10);		// 이거 안될거같은ㄷ 
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
		FlipBuffer();
		Sleep(1000);  // 잠깐 정지

		item.Reset();
		currentStageIndex++;
		LoadStage();
	}

	else if (currentStageIndex == 2 && item.IsStage3Clear())
	{
		CountDown();
		ClearBuffer();
		FlipBuffer();
		Sleep(1000);  // 잠깐 정지

		item.Reset();
		currentStageIndex++;
		LoadStage();
	}
	else if (currentStageIndex == 3 && item.IsStage4Clear())
	{
		ClearBuffer();
		FlipBuffer();
		Sleep(3000);
		
		ClearBuffer();
		EndingTitle();
		FlipBuffer();
		
		while (true)
		{
			if (_kbhit() && _getch() == 13)  // Enter 키
				break;
		}
		
		// 타이틀 화면으로 돌아가겠냐고 물은 다음 yes 하면 돌아가기
		ClearBuffer();  // 한 번 지우고 새 메시지
		WriteBuffer(50, 30, "타이틀 화면으로 돌아가시겠습니까? (Y/N)", 15);		// Y/N 선택창 띄워야하나 아니야 하지말자 
		FlipBuffer();   //  꼭 필요!!
		
		//  입력 버퍼 비우기
		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
		FlushConsoleInputBuffer(hInput);


		while (true)
		{
			if (_kbhit())
			{
				char input = _getch();
				if (input == 'y' || input == 'Y')
				{
					currentStageIndex = 0;
					item.Reset();
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					

					SetCurPosition(0, 0);
					ClearBuffer();
					ShowTItle();
					FlipBuffer();
					Sleep(1000);
					break;  // 타이틀로 돌아감
				}
				else if (input == 'n' || input == 'N')
				{
					ClearBuffer();
					WriteBuffer(35, 12, "게임을 종료합니다.", 7);
					FlipBuffer();
					Sleep(2000);
					exit(0);  // 종료
				}
			}
		}
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
void GameManager::PlayerMove(Player& player, Item& item)
{
	vector<vector<int>>& map = stage.GetMutableMap();
	if (_kbhit())
	{

		int dx = 0, dy = 0;		// 임시 좌표
	
		switch (_getch())
		{
		case 72: dy = -1; player.SetDirection(Direction::Up); break;	// 상 
		case 80: dy = 1;  player.SetDirection(Direction::Down); break;	// 하
		case 75: dx = -1; player.SetDirection(Direction::Left); break;	// 좌
		case 77: dx = 1;  player.SetDirection(Direction::Right); break;	// 우
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
			player.Move(dx, dy);	// 위치 업데이트

			// 새 위치에 플레이어 출력
			Pos newPos = player.GetPos();
			
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
			revealDuration = rand() % 3 + 3;  // 3~5초 == 5초간 맵 내부가 활성화된다는 멘트 추가하고 다시꺼질때 사라지게 하기 == 넣어야하나
			map[nextY][nextX] = TILE_EMPTY;		// 먹고나서 빈칸 초기화 
		}

	}
}