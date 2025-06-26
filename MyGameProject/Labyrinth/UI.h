#pragma once
#include "DoubleBuffer.h"
#include "GameManager.h"
#include "Item.h"

enum class MenuOption { Start, Rule, Exit };

MenuOption ShowMenu();

void ShowTItle();		// 게임 설명 추가하기 

void ShowTitle(int offsetY = -8, int color = 15);		// 타이틀을 그리기 위한 함수

void ShowGameRule();	// 게임 룰 함수

void CountDown();		// 다음스테이지 넘어가는 카운트다운

void EndingTitle(int offsetY = -8, int color = 15);		// 엔딩타이틀 그리기 위한 함수

//아이템 먹은거 확인하는 UI
// void DrawItemUI(int offsetX, int offsetY, int mapHeight);


//void Letter();


