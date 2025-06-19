#pragma once
#include "Exit.h"		// 2번째 스테이지에서 아이템을 다 먹어야 출구가 열리도록 햇지만 이게 필요한가라는 생각이 듦

class Item
{
public:
	Item() = default;
	Item(string itemShape, Exit& itemExit/* 여기도 일단 포인터로*/, ItemShape itemshape) : itemShape(itemShape), itemExit(itemExit), itemshape(itemshape) {}

	void ShapeConverter();		// 임시 함수 지울수도있음

};

//struct Item	// 아이템 구조체
//{
//	char* itemShape;
//	Exit itemExit;
//
//};
