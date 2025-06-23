#include "Player.h"
#include "MapBoder.h"

void Player::Move(int dx, int dy)
{
	playerPos += Pos{ dx, dy };
	
}


Pos Player::GetPos() const
{
	return playerPos;
}

void Player::SetPos(const Pos& pos)
{
	playerPos = pos;
}
