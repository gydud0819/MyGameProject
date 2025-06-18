#pragma once
#include "Exit.h"		// 2번째 스테이지에서 아이템을 다 먹어야 출구가 열리도록 햇지만 이게 필요한가라는 생각이 듦

enum ItemShape
{
	♥ = 2,
	♣,
};
class Item
{
	string itemShape;
	Exit& itemExit;		// 일단 선언은 하되 포인터로 넘겨받아도 되는지 모르겠으므로 일단 포인터로 받아옴, 참조로 받아야하나? 헷갈리네 
	ItemShape itemshape;
public:
	Item() = default;
	Item(string itemShape, Exit& itemExit/* 여기도 일단 포인터로*/, ItemShape itemshape) : itemShape(itemShape), itemExit(itemExit), itemshape(itemshape) {}

	void ShapeConverter();

};

//struct Item	// 아이템 구조체
//{
//	char* itemShape;
//	Exit itemExit;
//
//};
