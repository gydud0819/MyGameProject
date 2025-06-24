
#pragma once
#include "MapBoder.h"
#include "DoubleBuffer.h"
class Stage
{
private:
	bool isReveal;	// 랜턴 처리하는거 == 맵 내부를 드러내는지 확인하는 체크하는거
	bool isOuterWall;	// 벽인지 아닌지 확인하는거 
	bool isItem;
	vector<vector<int>> map;
public:
	Stage() = default;
public:
	void SetMap(const vector<vector<int>>& map);
	const vector<vector<int>>& GetMap() const;
	void RenderMap(const vector<vector<int>> map, Player& player, bool isReveal, int offsetX, int offsetY);
	vector<vector<int>>& GetMutableMap();
};


