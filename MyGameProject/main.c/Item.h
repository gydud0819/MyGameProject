#pragma once
//#include "Exit.h"		// 2번째 스테이지에서 아이템을 다 먹어야 출구가 열리도록 햇지만 이게 필요한가라는 생각이 듦
#include "MapBoder.h"
class Item : public MapBoder
{
	string Shape;
	TileType itemType;
public:
	Item() = default;
	Item(string Shape, TileType itemType) : Shape(Shape), itemType(itemType) {}
public:
	void Item1();		// void를 Pos로 받아올 수도 있음 
};

//struct Item	// 아이템 구조체
//{
//	char* itemShape;
//	Exit itemExit;
//
//};
