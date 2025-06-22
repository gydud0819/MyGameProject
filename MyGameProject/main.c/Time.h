#pragma once
#include "Console.h"

class TimeManager
{
	chrono::steady_clock::time_point startTime;
public:
	void Start();
	int GetElapsedSeconds() const;
	string GetFormattedTime() const;
};