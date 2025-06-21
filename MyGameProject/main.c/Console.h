#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 배경, 글자색 동시에 변경하는 함수
void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor);


void SetCurPosition(int x, int y);

void HideCursor();

void Startscreen();		// 게임 시작 화면 함수 

struct Pos		// 위치 구조체
{
	int posX;
	int posY;

	Pos& operator+=(const Pos& other)
	{
		posX += other.posX;
		posY += other.posY;

		return *this;	// 
	}
};