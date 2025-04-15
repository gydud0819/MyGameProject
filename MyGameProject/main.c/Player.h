#pragma once
#include "Console.h"

/*
* ����ü�� ������ �� � ���� ���� �����ؾ��ϴ��� �� �����ؾ��Ѵ�. �׷��� ������ ���� ������ ����ü�� �ν��� ���� ���ϴ� ��찡 �߻��Ͽ� ������ �� �� �ִ�. 
*/

struct Pos		// ��ġ ����ü
{
	int posX;
	int posY;
};

struct Exit	// �ⱸ ����ü
{
	Pos exitPos;
	bool exit;
};

struct Stage
{
	Pos stagePos;
	bool nextStage;
};

struct Item	// ������ ����ü
{
	char* itemShape;
	Exit itemExit;

};

struct Player	// �÷��̾� ����ü
{
	char* playerShape;
	Pos playerPos;
	BOOL NextStage;
	BOOL mazeExit;
	int heartCount;
	int starCount;
	int CurrentStage;
	int prevPosX;      
	int prevPosY;      

	void MovePlayer();
};

void MovePlayer(Player* playerptr, const Exit* exitptr);		// �÷��̾ �ܼ�â ������ �����̴� �Լ�


