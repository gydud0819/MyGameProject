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