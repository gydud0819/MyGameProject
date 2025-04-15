#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Player.h"

#define ���� 30
#define ���� 30

#define ����2 30
#define ����2 30

int Stage1[����][���� + 1];
int Stage2[����2][����2 + 1];

struct StagePos		// �������� ��ġ �̵���Ű�� ����ü
{
	int x;
	int y;
};

struct MapStage			// �������� ����ü
{
	char* name;
	char* (*stage)[����2 + 1];
	StagePos stagePos;
};

void ShowStage1(int* (*Stage)[���� + 1], COORD pos);	// �� ���ΰ� ���̴� �Լ�
void ShowClearStage1(int* (*Stage)[���� + 1], COORD pos);	// �� ���ΰ� ������ �ʴ� �Լ�

void ShowStage2(int* (*Stage)[����2 + 1], COORD Nextpos);	// �ι�° �� �Լ�
void ShowClearStage2(int* (*Stage)[����2 + 1], COORD Nextpos);		// �� ���ΰ� ������ �ʴ� 2��° �������� �Լ�


void ShowExit();	// �������� �� ���� �� �ⱸ�� ��Ÿ���� �Լ�

