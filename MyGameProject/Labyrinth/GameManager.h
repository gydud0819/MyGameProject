#pragma once

#include "ConsoleUtil.h"
#include "DoubleBuffer.h"
#include "MapBoder.h"
#include "Player.h"
#include "Stage.h"
#include "Item.h"
#include "Time.h"
#include "UI.h"
//#include "HeartItem.h"
//#include "StarItem.h"
//#include "CloverItem.h"

class GameManager 		// Is-a 관계 생각하기
{
	// 핵심 객체들
	Stage stage;
	MapBoder mapboder;
	Player player;
	Item item;

	// 게임 상태 관련 
	bool isRevealMap = false;		// 맵 보여주는걸 bool로 참 거짓 판단
	int currentStageIndex = 0;		// 현재 스테이지
	int revealDuration = 0;		// 보여주는 시간 = revealDuration
	chrono::steady_clock::time_point revealStartTime;		// 프로그램 내부에서 시간 측정을 하기위해 쓰는 함수 


	Time time;
	vector<vector<int>> currentMap;	// 현재 맵


	static bool isFirst;			// 게임 시작할 때 딱 1번만 실행되게 설정	
	static bool isBufferInit;  // 버퍼 초기화도 딱 1번만 하게				
public:
	GameManager() = default;
	GameManager(Player player) : player(player) {}

	~GameManager();		//  일단 냅두자 
public:
	bool Play();		// 메인 코드에서 이거만 호출해서 플레이 해야함
	void ShowMap();		// 맵 보여주는 함수
	void PlayerMove(Player& player, Item& item); // 플레이어가 맵 내에서만 돌아다니도록 하는 함수
	void RenderMap();		// 
	void CheckStageClear(Item& item);
	void LoadStage();	// 다음 스테이지 불러오는 함수
	void Update();
	void DrawItemUI(int offsetX, int offsetY, int mapHeight);

};
