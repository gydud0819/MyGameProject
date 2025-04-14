#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>

void ItemRandomSeed();	// 시작할 때 마다 아이템이 랜덤으로 배치 되도록 하는 함수

int ItemPosX();
int ItemPosY();