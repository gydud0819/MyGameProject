#pragma once
#include "Console.h"

extern HANDLE hBuffer[2];
extern int screenIndex;

const int BufferWidth = 150;		// 기본 창은 240이지만 맵 정렬이 150x60으로 되어있기 때문에 얘도 추후 수정
const int BufferHeight = 60;
const int LogicalWidth = 150;		// 맵 정렬을 위한 고정한 가로 버퍼 

void InitBuffer();
void FlipBuffer();
void ClearBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void ReleaseBuffer();
