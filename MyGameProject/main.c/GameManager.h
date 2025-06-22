#pragma once
#include "Console.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"
#include "Stage.h"
#include "MapBoder.h"
#include "Buffer.h"

class GameManager /*: public MapBoder*/		// Is-a 관계 생각하기
{
	Stage stage;
	MapBoder mapboder;
	Player player;
	int currentStageIndex = 0;

	Item item;

	vector<vector<int>> currentMap;	// 현재 맵

	/*bool isRevealMap = false;
	chrono::steady_clock::time_point revealStartTime;
	int revealDuration = 0;*/		// 보여주는 시간 = revealDuration
public:
	GameManager() = default;
	GameManager(Player player) : player(player) {}
public:
	void Play();		// 메인 코드에서 이거만 호출해서 플레이 해야함
	void ShowMap();		// 맵 보여주는 함수
	void PlayerMove(Player& player, vector<vector<int>>& map, Item& item); // 플레이어가 맵 내에서만 돌아다니도록 하는 함수
	void RenderMap();
	void CheckStageClear(Item& item);
	void CountDown();
	void LoadStage();
	void Update();
};
