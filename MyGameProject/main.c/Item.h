#pragma once
#include "MapBoder.h"
class Item		// 나중에 상속으로 분리하기 
{
	int heartCount = 0;		// stage1 열쇠
	int starCount = 0;		// stage2 열쇠
	int cloverCount = 0;	// stage3 열쇠
public:
	Item() = default;
	//Item(string shape, TileType itemType) : shape(shape), itemType(itemType), count(0) {}		// 이니셜라이저 초기화는 일단 보류
public:

	void Collect(int tileType);

	int GetItem1Count() const;
	int GetItem2Count() const;
	int GetItem3Count() const;

	void Reset();

	bool IsStage1Clear() const;
	bool IsStage2Clear() const;
	bool IsStage3Clear() const;

};



// 아이템 클래스에 필요한 내용
