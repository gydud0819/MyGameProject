#pragma once
#include "Stage.h"
class Exit : public Stage
{
	Pos exitPos;
	bool exit;

public:
	Exit() = default;
	Exit(Pos exitPos, bool exit) : exitPos(exitPos), exit(false) /* 2번째 스테이지에서도 아이템을 다 먹어야 true로 변환됨*/ {}
};

struct Exit	// 출구 구조체
{
	Pos exitPos;
	bool exit;
};