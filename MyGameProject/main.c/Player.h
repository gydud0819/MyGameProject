#pragma once
#include "Console.h"
#include "Exit.h"
// 벡터 써도 되나? 

//struct Player	// 플레이어 구조체
//{
//	char* playerShape;		// -> string Shpae 바꿀 예정
//	Pos playerPos;			// pos는 독자적으로 사용해야하니까 struct로 그대로 쓸 예정
//	BOOL NextStage;			// 이건 그대로 냅둬야할듯
//	BOOL mazeExit;			// 얘도 
//	int heartCount;
//	int starCount;
//	int CurrentStage;
//	int prevPosX;			// preX로 이름 변경예정
//	int prevPosY;			// preY로 변수이름 변경예정
//
//	void MovePlayer();		// 이건 아마 밑에 있는 함수랑 같을거지만 public으로 선언은 해야함
//};

//void MovePlayer();		// 플레이어가 콘솔창 내에서 움직이는 함수, -> 함수 안 매개인자를 참조로 받아서 넘길예정)

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
};

