#pragma once
#include "DoubleBuffer.h"
#include "GameManager.h"

enum class MenuOption { Start, Rule, Exit };

MenuOption ShowMenu();

void ShowTItle();		// 게임 설명 추가하기 

void ShowTitle(int offsetY = -8, int color = 15);

void ShowGameRule();

void CountDown();

void EndingTitle(int offsetY = -8, int color = 15);


