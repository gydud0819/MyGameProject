#pragma once
#pragma once
#include "ConsoleUtil.h"
#include "DoubleBuffer.h"

class Time
{
	chrono::steady_clock::time_point startTime;
	chrono::time_point<std::chrono::steady_clock> endTime;
public:
	void Start(); // 시작 시간 기록
	void End();		// 종료 시간 기록
	int GetElapsedSeconds() const;	// 경과 초
	void DisplayPlayTime(int offsetX, int offsetY) const; // 콘솔에 시간 출력
};

//void CountDown();	// 스테이지 넘어갈때 카운트다운 나오는 함수 
