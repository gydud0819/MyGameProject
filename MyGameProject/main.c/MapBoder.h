#pragma once
#include "Console.h"
#include "Player.h"

// 벡터로 맵을 표현할 수 있나? ■ 이건데 

struct StagePos		// 스테이지 위치 이동시키는 구조체
{
	int x;
	int y;
};


//void ShowExit();	// 아이템을 다 먹은 후 출구를 나타내는 함수

enum TileType			// 맵 모양을 enum으로 
{
	TILE_EMPTY = 0,		// 길
	TILE_WALL,		// 벽
	TILE_ITEM1,		// 아이템 1
	TILE_ITEM2		// 아이템 2
};

class MapBoder			// 나중에 벡터로 표현하기 tq
{
private:
	Pos pos;		// 스테이지 위치 이동시키는 거
	Pos NextPos;	// 다음 스테이지로 넘어가는 거

	
	vector<vector<int>> map1;	// 이중벡터를 써야함 벡터도 겨우 쓰는데 이중벡터를 쓰라니 미친게임 왜만들엇지? 
	vector<vector<int>> map2;	// 이중벡터를 써야함 벡터도 겨우 쓰는데 이중벡터를 쓰라니 미친게임 왜만들엇지? 

public:
	MapBoder() = default;
	MapBoder(Pos pos, Pos NextPos) : pos(pos), NextPos(NextPos) {} // 초기화를 잘못했나
	
public:
	void InitMap();
	//void ShowStage1();	// 맵 내부가 보이는 함수
	void ShowClearStage1();	// 맵 내부가 보이지 않는 함수 -> main

	void InitMap2();
	//void ShowStage2();	// 두번째 맵
	void ShowClearStage2();		// 맵 내부가 보이지 않는 2번째 스테이지 함수

};

// 오늘 할일 : map을 vector로 표현하기가 아닌 플레이어을ㄹ 맵안에서 움직이게 하기 tlqkf 될거같은데안되니까 더 빡치네
/*
* 
*/

