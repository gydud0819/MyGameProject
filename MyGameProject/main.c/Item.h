#pragma once
//#include "Exit.h"		// 2번째 스테이지에서 아이템을 다 먹어야 출구가 열리도록 햇지만 이게 필요한가라는 생각이 듦
#include "MapBoder.h"
class Item 
{
	int heartCount = 0;		// stage1 열쇠
	int starCount = 0;		// stage2 열쇠
	int cloverCount = 0;	// stage3 열쇠
public:
	//Item() = default;
	//Item(string shape, TileType itemType) : shape(shape), itemType(itemType), count(0) {}
public:
	//void CheckItem(Player& player, vector<vector<int>>& map);		// void를 Pos로 받아올 수도 있음 
	//int GetCount() const;
	//TileType GetItemType() const;

	void Collect(int tileType);

	int GetItem1Count() const;
	int GetItem2Count() const;

	void Reset();

	bool IsStage1Clear() const;
	bool IsStage2Clear() const;
	bool IsStage3Clear() const;


};



// 아이템 클래스에 필요한 내용
