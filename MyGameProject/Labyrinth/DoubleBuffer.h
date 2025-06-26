#pragma once
#include "ConsoleUtil.h"

extern HANDLE hBuffer[2];			// 창 2개 제어
extern int screenIndex;

const int BufferWidth = 150;		// 기본 창은 240이지만 맵 정렬이 150x60으로 되어있기 때문에 얘도 추후 수정
const int BufferHeight = 60;

void SetConsoleSize(int width, int height);
void InitBuffer();																	// 콘솔 버퍼 2개 생성 및 초기화하는 함수
void FlipBuffer();																	// 버퍼 뒤집기
void ClearBuffer();																	// 버퍼 비우기
void WriteBuffer(int x, int y, const char* shape, int color);						// 버퍼로 문자열 표현
void ReleaseBuffer();																// 버퍼 실행 종료
void WriteCenter(const char* text, int yOffset, int color = 7);						// 중앙 정렬로 WriteBuffer 해주는 함수
void ResizeConsole();																// 
void WriteCenterAdjusted(const char* text, int yOffset, int color, int xAdjust);
void WriteCenterDynamic(const char* text, int yOffset, int color = 7);				// 콘솔창 기준 문자열 중앙 정렬 함수





