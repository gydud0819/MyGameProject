#pragma once
#include "Console.h"
#include "MapBoder.h"
#include "Buffer.h"
class Stage 
{
	//Pos stagePos;
	//bool nextStage;

public:
	Stage() = default;
public:
	//void Stage1(vector<vector<int>> map1);
	//void Stage2(vector<vector<int>> map2);

	void RenderMap(const vector<vector<int>> map, Player& player);
};


