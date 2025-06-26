#include "Stage.h"

void Stage::RenderMap(const vector<vector<int>> map, Player& player, bool isReveal, int offsetX, int offsetY)
{
	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			// 외곽 벽 또는 아이템 여부를 판단 (항상 표시되어야 하므로 예외 처리)
			isOuterWall = (x == 0 || x == map[0].size() - 1 || y == 0 || y == map.size() - 1);
			isItem = (map[y][x] == TILE_ITEM1 || map[y][x] == TILE_ITEM2 || map[y][x] == TILE_ITEM3 || map[y][x] == TILE_ITEM4);

			// 랜턴이 없는 상태일 때, 플레이어 주변 3x3 범위만 출력 (어둠 표현용 제한 시야)
			// 외곽 벽, 아이템이 아닌 경우 → 즉, 플레이어가 실제로 이동할 수 있는 '길'일 때만 시야 제한 적용
			if (!isReveal && !isOuterWall && !isItem)	
			{
				// 현재 좌표와 플레이어 위치 간의 거리 차이 계산
				int dx = abs(x - player.GetPos().posX);
				int dy = abs(y - player.GetPos().posY);

				// 거리 차이가 1칸 이상이면(3x3 바깥이면) 출력 제외 -> 시야에서 제외됨
				if (dx > 1 || dy > 1) continue;
			}

			int drawX = x + offsetX * 2;  // 콘솔 가로는 2배 처리
			int drawY = y + offsetY;

			char symbol = ' ';
			int color = 7;

			switch (map[y][x])
			{
			case TILE_WALL: WriteBuffer(drawX, drawY, "#", 7); break;
				
			case TILE_EMPTY: WriteBuffer(drawX, drawY, " ", 0); break;
				
			case TILE_ITEM1: WriteBuffer(drawX, drawY, "♥", 4); break;
			
			case TILE_ITEM2: WriteBuffer(drawX, drawY, "★", 6); break;
			
			case TILE_ITEM3: WriteBuffer(drawX, drawY, "&", 14); break;
			
			case TILE_ITEM4: WriteBuffer(drawX, drawY, "♣", 10); break;
			
			default: WriteBuffer(drawX, drawY, "?", 7); break; // 예외 디버깅 => 다른 아이템을 넣엇을때
				
			}
		}
	}

	Pos p = player.GetPos();
	const char* dirSymbol = "◈";  // 기본 캐릭터

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

void Stage::SetMap(const vector<vector<int>>& map)
{
	this->map = map;
}

const vector<vector<int>>& Stage::GetMap() const
{
	return map;
	// TODO: 여기에 return 문을 삽입합니다.
}
