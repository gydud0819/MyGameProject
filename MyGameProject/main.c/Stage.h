#pragma once
#include "Console.h"
#include "MapBoder.h"
#include "Buffer.h"
class Stage 
{
private:
bool isReveal;	// 랜턴 처리하는거 == 맵 내부를 드러내는지 확인하는 체크하는거
bool isOuterWall;
bool isItem; 
std::vector<std::vector<int>> map;
public:
	Stage() = default;
public:
	void SetMap(const std::vector<std::vector<int>>& map);
	const std::vector<std::vector<int>>& GetMap() const;
	void RenderMap(const vector<vector<int>> map, Player& player, bool isReveal, int offsetX, int offsetY);
	vector<vector<int>>& GetMutableMap() ;
};


