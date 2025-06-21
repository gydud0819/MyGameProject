#include "Stage.h"

//void Stage::Stage1(vector<vector<int>> map1)
//{
//	for (int y = 0; y < map1.size(); y++)
//	{
//		for (int x = 0; x < map1[y].size(); x++)	// 현재 y행의 x칸들을 모두 탐색
//		{
//			SetCurPosition(x, y);
//
//			switch (map1[y][x])
//			{
//			case TILE_WALL:
//
//				SetColor(0, (x == 0 || x == 29 || y == 0 || y == 29) ? 15 : 0);
//				cout << ("■");
//				break;
//
//			case TILE_EMPTY:
//				SetColor(0, (x == 0 || y == 0) ? 0 : 0);
//				cout << (" ");
//				break;
//
//			case TILE_ITEM1:
//				SetColor(0, 4);
//				cout << ("♥");
//				SetColor(0, 15);
//				break;
//
//			case TILE_ITEM2:
//				SetColor(0, 6);			// 함수로 만들어서 따로 처리하기 나중에
//				cout << ("★");
//				SetColor(0, 15);
//				break;
//
//			default:
//				cout << "?"; // 디버깅용 표시
//				break;
//			}
//		}
//	}
//}
//
//void Stage::Stage2(vector<vector<int>> map2)
//{
//	for (int y = 0; y < map2.size(); y++)
//	{
//		for (int x = 0; x < map2[y].size(); x++)	// 현재 y행의 x칸들을 모두 탐색
//		{
//			SetCurPosition(x, y);
//
//			switch (map2[y][x])
//			{
//			case TILE_WALL:
//
//				SetColor(0, (x == 0 || x == 29 || y == 0 || y == 29) ? 15 : 0);
//				cout << ("■");
//				break;
//
//			case TILE_EMPTY:
//				SetColor(0, (x == 0 || y == 0) ? 0 : 0);
//				cout << (" ");
//				break;
//
//			case TILE_ITEM1:
//				SetColor(0, 4);
//				cout << ("♥");
//				SetColor(0, 15);
//				break;
//
//			case TILE_ITEM2:
//				SetColor(0, 6);			// 함수로 만들어서 따로 처리하기 나중에
//				cout << ("★");
//				SetColor(0, 15);
//				break;
//
//			default:
//				cout << "?"; // 디버깅용 표시
//				break;
//			}
//		}
//	}
//}

void Stage::RenderMap(const vector<vector<int>> map, Player& player)
{
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
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

			default:
				WriteBuffer(x, y, "?", 7); // 예외 디버깅
				break;
			}
		}
	}
}
