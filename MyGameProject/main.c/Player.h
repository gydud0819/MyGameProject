#pragma once
#include "Console.h"

class Player
{
private:
	// 플레이어 위치
	Pos playerPos;
public:
	Player() = default;		// 생성자

	Player(Pos playerPos) : playerPos(playerPos){} // Has - A 플레이어는 움직임을 가진다 == 플레이어는 움직인다

	void Move(int dx, int dy);	// 이 함수는 플레이어가 이동할 거리를 측정하는 함수
	
	Pos GetPos() const;

	void SetPos(const Pos& pos);
};

