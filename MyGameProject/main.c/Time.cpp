#include "Time.h"

void TimeManager::Start()
{
	startTime = chrono::steady_clock::now();
}

int TimeManager::GetElapsedSeconds() const
{
	auto now = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
}


