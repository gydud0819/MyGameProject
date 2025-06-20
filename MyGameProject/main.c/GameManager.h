#pragma once
#include "Console.h"
#include "Player.h"
#include "Exit.h"
#include "Item.h"
#include "Stage.h"
#include "MapBoder.h"

class GameManager
{
	Stage stage;
	//MapBoder map;
	Player player;
public:
	GameManager() = default;
	GameManager(Stage stage, Player player) : stage(stage), player(player) {}
public:
	void Play();		// 메인 코드에서 이거만 호출해서 플레이 해야함
	void ShowMap();		
	void PlayerMove(Player& player, Stage& stage); // playerove안에 맵을 안벗어나게 처리를 해야 하나? 그럼 매개인자 받아야하는거 아닌가
};