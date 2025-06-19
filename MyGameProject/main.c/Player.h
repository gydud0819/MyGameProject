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
	// 플레이어 모양이 필요한가?  -> 일단 보류
	string Shape;
	
	// 플레이어 위치
	Pos playerPos;


	int heartCount;
	int starCount;
	int CurrentStage;
	int preX;			
	int preY;

public:
	// Has-A 플레이어가 이 동작을 하도록
	//BOOL NextStage;		// protected로 넘길수도 있음
	//BOOL mazeExit;

public:
	Player() = default;		// 생성자

	Player(string Shape, Pos playerPos, int heartCount, int starCount, int CurrentStage, int preX, int preY) :
		Shape(Shape), playerPos(playerPos), heartCount(heartCount) /* 5로 초기화하는 이유는 맵 내부 아이템 개수가 5개라서*/, starCount(starCount), CurrentStage(CurrentStage),
		preX(preX), preY(preY) { }

	void MovePlayer(Player& player, Pos& playerPos);		// Player랑 Exit는 참조로 받아와 넘겨야한다.
	
};

