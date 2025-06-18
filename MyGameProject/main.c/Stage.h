#pragma once
#include "Console.h"
class Stage
{
	Pos stagePos;
	bool nextStage;

public:
	Stage() = default;
	Stage(Pos stagePos, bool nextStage) : stagePos(stagePos), nextStage(false)/* false로 초기화 하는 이유 : 아이템을 다 먹었을 때 true로 바뀌어야 하니까*/ {}
};

//struct Stage
//{
//	Pos stagePos;
//	bool nextStage;
//};
