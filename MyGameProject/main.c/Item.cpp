#include "Item.h"
//#include "Item.h"
//
//void Item::Item1()
//{
//	switch (itemType)
//	{
//	case TILE_EMPTY: return " ";
//		break;
//	case TILE_WALL: return "бс";
//		break;
//	case TILE_ITEM1:
//		break;
//	case TILE_ITEM2:
//		break;
//	default:
//		break;
//	}
//}
//
//void Item::CheckItem(Player& player, vector<vector<int>>& map)
//{
//	Pos pos = player.GetPos();
//	int& tile = map[pos.posY][pos.posY];
//
//
//
//	if (tile == itemType)
//	{
//		count++;
//
//	}
//}

void Item::Collect(int tileType)
{
	if (tileType == TILE_ITEM1) heartCount++;
	else if (tileType == TILE_ITEM2) starCount++;
	else if (tileType == TILE_ITEM4) cloverCount++;
}

int Item::GetItem1Count() const
{
	return heartCount;
}

int Item::GetItem2Count() const
{
	return starCount;
}

void Item::Reset()
{
	heartCount = 0;
	starCount = 0;
	cloverCount = 0;
}

bool Item::IsStage1Clear() const
{
	return heartCount >= 5;
}

bool Item::IsStage2Clear() const
{
	return starCount >= 5;
}

bool Item::IsStage3Clear() const
{
	return cloverCount >= 3;
}


