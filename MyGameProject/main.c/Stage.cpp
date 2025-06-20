#include "Stage.h"

void Stage::Stage1(vector<vector<int>> map1)
{
	for (int y = 0; y < map1.size(); y++)
	{
		for (int x = 0; x < map1.size(); x++)
		{
			SetCurPosition(x, y);

			switch (map1[y][x])
			{
			case TILE_WALL:

				SetColor(0, (x == 0 || x == 29 || y == 0 || y == 29) ? 15 : 0);
				cout << ("■");
				break;

			case TILE_EMPTY:
				SetColor(0, (x == 0 || y == 0) ? 0 : 0);
				cout << (" ");
				break;

			case TILE_ITEM1:
				SetColor(0, 4);
				cout << ("♥");
				SetColor(0, 15);
				break;

			case TILE_ITEM2:
				SetColor(0, 6);			// 함수로 만들어서 따로 처리하기 나중에
				cout << ("★");
				SetColor(0, 15);
				break;

			default:
				cout << "?"; // 디버깅용 표시
				break;
			}
		}
	}
}
