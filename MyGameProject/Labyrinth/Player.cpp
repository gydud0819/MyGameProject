#include "Player.h"

void Player::Move(int dx, int dy)
{
	if (dx == -1) direction = Direction::Left;
	else if (dx == 1) direction = Direction::Right;
	else if (dy == -1) direction = Direction::Up;
	else if (dy == 1) direction = Direction::Down;

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

void Player::SetDirection(Direction dir)
{
	direction = dir;
}


Direction Player::GetDirection() const
{
	return direction;		// enum으로 설정한 방향 반환
}
