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


/*\
* 내일 할거
* 1. 맵 내부가 보이는 함수와 보이지 함수 만들어서 구분하기 (가장 먼저하기) - 완료
* 2. 두번째 스테이지 만들기
* 3. 첫번째 스테이지를 통과하면 두번째 스테이지로 넘어가도록 수정하기
* 4. 게임 시작 종료 로고 만들기 
*/

typedef struct _STAGEPOS		// 스테이지 위치 이동시키는 구조체
{
	int x;
	int y;
}StagePos;

typedef struct _MOVESTAGE			// 스테이지 구조체
{
	char* name;
	char* (*stage)[가로2 + 1];
	StagePos stagePos;
}MStage;

void ShowStage1(int* (*Stage)[가로 + 1], COORD pos);	// 맵 내부가 보이는 함수
void ShowClearStage1();	// 맵 내부가 보이지 않는 함수

void ShowStage2(int* (*Stage)[가로2 + 1], COORD Nextpos);	// 두번째 맵 함수
void ShowClearStage2();		// 맵 내부가 보이지 않는 2번째 스테이지 함수


void ShowExit();	// 아이템을 다 먹은 후 출구를 나타내는 함수

