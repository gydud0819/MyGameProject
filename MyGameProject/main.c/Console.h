#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

// 배경, 글자색 동시에 변경하는 함수
void SetColor(unsigned char _BackGroundColor, unsigned char _Textcolor);

void SetCurPosition(int x, int y);

void HideCursor();

void Startscreen();		// 게임 시작 화면 함수 