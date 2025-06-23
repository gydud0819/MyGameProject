#include "Stage.h"

void Stage::RenderMap(const vector<vector<int>> map, Player& player, bool isReveal, int offsetX, int offsetY)
{
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			// 랜턴 처리하는 코드 확실하지 않음
			isOuterWall = (x == 0 || x == map[0].size() - 1 || y == 0 || y == map.size() - 1);
			isItem = (map[y][x] == TILE_ITEM1 || map[y][x] == TILE_ITEM2 || map[y][x] == TILE_ITEM3||map[y][x] == TILE_ITEM4);

			if (!isReveal && !isOuterWall && !isItem)	// 랜턴으로 플레이어 기준 x,y 2칸씩만 밝혀주는 기본 기능 
			{
				int dx = abs(x - player.GetPos().posX);
				int dy = abs(y - player.GetPos().posY);
				if (dx > 2 || dy > 2) continue;
			}

			int drawX = x + offsetX * 2;  // 콘솔 가로는 2배 처리
			int drawY = y + offsetY;


			/*if (player.GetPos().posX == x && player.GetPos().posY == y)
			{
				WriteBuffer(drawX, drawY, "◈", 15);
				continue;
			}*/

			char symbol = ' ';
			int color = 7;

			switch (map[y][x])
			{
			case TILE_WALL:
				WriteBuffer(drawX, drawY, "■", 15);
				break;

			case TILE_EMPTY:
				WriteBuffer(drawX, drawY, " ", 0);
				break;

			case TILE_ITEM1:
				WriteBuffer(drawX, drawY, "♥", 4);
				break;

			case TILE_ITEM2:
				WriteBuffer(drawX, drawY, "★", 6);
				break;

			case TILE_ITEM3:
				WriteBuffer(drawX, drawY, "#", 6);
				break;
				
			case TILE_ITEM4:
				WriteBuffer(drawX, drawY, "♣", 12);
				break;
			default:
				WriteBuffer(drawX, drawY, "?", 7); // 예외 디버깅
				break;
			}
		}
	}

	Pos p = player.GetPos();
	const char* dirSymbol = "◈";  // 기본값

	switch (player.GetDirection())
	{
	case Direction::Up:    dirSymbol = "▲"; break;
	case Direction::Down:  dirSymbol = "▼"; break;
	case Direction::Left:  dirSymbol = "◀"; break;
	case Direction::Right: dirSymbol = "▶"; break;
	}

	WriteBuffer(p.posX + offsetX * 2, p.posY + offsetY, dirSymbol, 15);
	//                   ↑ 콘솔 가로는 2배 처리

}

vector<vector<int>>& Stage::GetMutableMap() 
{
	return map;
	// TODO: 여기에 return 문을 삽입합니다.
}

void Stage::SetMap(const std::vector<std::vector<int>>& map)
{
	this->map = map;
}

const std::vector<std::vector<int>>& Stage::GetMap() const
{
	return map;
	// TODO: 여기에 return 문을 삽입합니다.
}
