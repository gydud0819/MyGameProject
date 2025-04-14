#include "Random.h"

void ItemRandomSeed()
{
	// 아이템이 시작할 때 마다 랜덤으로 배치가 되어야 한다.
	srand(time(NULL) % 20);
}

int ItemPosX()
{
	int randValue = rand() % 20 + 2;
	return randValue % 2 == 0 ? randValue : randValue + 2;
}

int ItemPosY()
{
	int randValue = rand() % 20;
	return randValue;
}
