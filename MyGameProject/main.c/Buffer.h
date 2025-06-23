#pragma once
#include "Console.h"

extern HANDLE hBuffer[2];
extern int screenIndex;

const int BufferWidth = 150;
const int BufferHeight = 60;

void InitBuffer();
void FlipBuffer();
void ClearBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void ReleaseBuffer();