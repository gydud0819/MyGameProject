#include "Item.h"

// 상속으로 분리하기전 임시 코드 
void Item::Collect(int itemType)
{
	if (itemType == TILE_ITEM1) heartCount++;
	else if (itemType == TILE_ITEM2) starCount++;
	else if (itemType == TILE_ITEM4) cloverCount++;
}

int Item::GetItem1Count() const
{
	return heartCount;
}

int Item::GetItem2Count() const
{
	return starCount;
}

int Item::GetItem3Count() const
{
	return cloverCount;
}

void Item::Reset()
{
	heartCount = 0;
	starCount = 0;
	cloverCount = 0;
}

bool Item::IsStage1Clear() const
{
	return heartCount >= 1;
}

bool Item::IsStage2Clear() const
{
	return starCount >= 1;
}

bool Item::IsStage3Clear() const
{
	return cloverCount >= 1;
}

bool Item::IsStage4Clear() const
{
	return heartCount >= 2 && starCount >= 2 && cloverCount >= 2;
}



