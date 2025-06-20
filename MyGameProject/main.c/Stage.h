#pragma once
#include "Console.h"
#include "MapBoder.h"
class Stage : public MapBoder
{
	//Pos stagePos;
	//bool nextStage;

public:
	Stage() = default;
	Stage() { }
public:
	void Stage1(vector<vector<int>> map1);
};

//struct Stage
//{
//	Pos stagePos;
//	bool nextStage;
//};
