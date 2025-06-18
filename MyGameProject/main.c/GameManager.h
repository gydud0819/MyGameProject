#pragma once
#include "Console.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"
#include "Stage.h"

class GameManager
{
private:
	Player& player;
	Exit Stage1Exit;
	Exit Stage3Exit;
	Stage stage;
	vector<Item> stage1Items;	// 참조로 안받아도 되나?
	vector<Item> stage2Items;
public:
	GameManager() = default;
	GameManager(Player& player, Stage& stage) : player(player), stage(stage) {}		// 
	void InitializeGame();     // 게임 초기화
	void Update();             // 프레임 업데이트

private:
	void CheckStageTransition();   // 스테이지 전환 체크
	void CheckItemCollection();    // 아이템 획득 체크
	void ActivateExit();           // 출구 활성화
	void RenderGame();
};