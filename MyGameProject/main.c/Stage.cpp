#include "Stage.h"

void Stage::RenderMap(const vector<vector<int>> map, Player& player, bool isReveal)
{
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			// 랜턴 처리하는 코드 확실하지 않음
			/*bool isOuterWall = (x == 0 || x == map[0].size() - 1 || y == 0 || y == map.size() - 1);
			bool isItem = (map[y][x] == TILE_ITEM1 || map[y][x] == TILE_ITEM2 || map[y][x] == TILE_ITEM3);

			if (!isReveal && !isOuterWall && !isItem)
			{
				int dx = abs(x - player.GetPos().posX);
				int dy = abs(y - player.GetPos().posY);
				if (dx > 2 || dy > 2) continue;
			}*/

			SetCurPosition(x, y);

			if (player.GetPos().posX == x && player.GetPos().posY == y)
			{
				WriteBuffer(x, y, "◈", 15);
				continue;
			}

			switch (map[y][x])
			{
			case TILE_WALL:
				/*SetColor(0, (x == 0 || x == 29 || y == 0 || y == 29) ? 15 : 15);
				std::cout << "■";*/
				WriteBuffer(x, y, "■", 15);
				break;

			case TILE_EMPTY:
				WriteBuffer(x, y, " ", 0);
				/*SetColor(0, 0);
				std::cout << " ";*/
				break;

			case TILE_ITEM1:
				WriteBuffer(x, y, "♥", 4);
				/*SetColor(0, 4);
				std::cout << "♥";
				SetColor(0, 15);*/
				break;

			case TILE_ITEM2:
				WriteBuffer(x, y, "★", 6);
			/*	SetColor(0, 6);
				std::cout << "★";
				SetColor(0, 15);*/
				break;

			case TILE_ITEM3:
				WriteBuffer(x, y, "#", 6);
				/*	SetColor(0, 6);
					std::cout << "★";
					SetColor(0, 15);*/
				break;
				
			case TILE_ITEM4:
				WriteBuffer(x, y, "♣", 12);
				break;
			default:
				WriteBuffer(x, y, "?", 7); // 예외 디버깅
				break;
			}
		}
	}
}
