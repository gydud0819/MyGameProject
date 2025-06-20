#include "Item.h"

void Item::Item1()
{
	switch (itemType)
	{
	case TILE_EMPTY: return " ";
		break;
	case TILE_WALL: return "бс";
		break;
	case TILE_ITEM1:
		break;
	case TILE_ITEM2:
		break;
	default:
		break;
	}
}
