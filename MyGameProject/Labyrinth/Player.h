#pragma once
#include "ConsoleUtil.h"
#include "MapBoder.h"

enum class Direction	// 플레이어 방향키 
{
	Up,		// ▲
	Down,	// ▼
	Left,	// ◀
	Right	// ▶
};

class Player
{
private:
	Pos playerPos;
	Direction direction;

public:
	Player() = default;		// 생성자

	Player(Pos playerPos, Direction direction = Direction::Down) : playerPos(playerPos), direction(direction) {} // Has - A 플레이어는 움직임을 가진다 == 플레이어는 움직인다

	void Move(int dx, int dy);	// 방향키대로 눌렀을때 

	Pos GetPos() const;			// 플레이어 방향을 받아오는 함수

	void SetPos(const Pos& pos);		// 방향 설정하는 함수
	void SetDirection(Direction dir);	// 플레이어 방향키 모양 세팅하는 하뭇
	Direction GetDirection() const;
};

