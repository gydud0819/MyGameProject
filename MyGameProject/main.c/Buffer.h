#pragma once
#include "Console.h"

extern HANDLE hBuffer[2];
extern int screenIndex;

const int BufferWidth = 200;
const int BufferHeight = 200;

void InitBuffer();
void FlipBuffer();
void ClearBuffer();
void WriteBuffer(int x, int y, const char* shape, int color);
void ReleaseBuffer();