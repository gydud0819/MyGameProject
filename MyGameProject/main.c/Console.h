#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

// 배경, 글자색 동시에 변경하는 함수
void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor);


void SetCurPosition(int x, int y); // 커서 위치 옮기는 함수
	
void HideCursor();		// 커서 숨기는 함수

void Startscreen();		// 게임 시작 화면 함수 

void ShowTitle(int offsetY = -8, int color = 15);		// 타이틀 그려놓은거 

struct Pos		// 위치 구조체
{
	int posX;
	int posY;

	Pos& operator+=(const Pos& other)	// 연산자 오버로딩
	{
		posX += other.posX;
		posY += other.posY;

		return *this;	// 
	}
};