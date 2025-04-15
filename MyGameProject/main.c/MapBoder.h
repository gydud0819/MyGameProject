#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Player.h"

#define 가로 30
#define 세로 30

#define 가로2 30
#define 세로2 30

int Stage1[세로][가로 + 1];
int Stage2[세로2][가로2 + 1];

struct StagePos		// 스테이지 위치 이동시키는 구조체
{
	int x;
	int y;
};

struct MapStage			// 스테이지 구조체
{
	char* name;
	char* (*stage)[가로2 + 1];
	StagePos stagePos;
};

void ShowStage1(int* (*Stage)[가로 + 1], COORD pos);	// 맵 내부가 보이는 함수
void ShowClearStage1(int* (*Stage)[가로 + 1], COORD pos);	// 맵 내부가 보이지 않는 함수

void ShowStage2(int* (*Stage)[가로2 + 1], COORD Nextpos);	// 두번째 맵 함수
void ShowClearStage2(int* (*Stage)[가로2 + 1], COORD Nextpos);		// 맵 내부가 보이지 않는 2번째 스테이지 함수


void ShowExit();	// 아이템을 다 먹은 후 출구를 나타내는 함수

