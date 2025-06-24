#include "Time.h"

void Time::Start()
{
	startTime = std::chrono::steady_clock::now();
}

void Time::End()
{
	endTime = std::chrono::steady_clock::now();
}

int Time::GetElapsedSeconds() const
{
	auto now = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
}

void Time::DisplayPlayTime(int offsetX, int offsetY) const
{
	char clear[50] = "                         "; // 길이 충분히 확보
	WriteBuffer(offsetX, offsetY, clear, 0);       // 검은색(0)으로 지우기
	auto now = std::chrono::steady_clock::now(); // 현재 시간
	int seconds = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
	int minutes = seconds / 60;
	int hours = minutes / 60;
	seconds %= 60;
	minutes %= 60;

	char buffer[50];
	sprintf_s(buffer, "Play Time: %02d:%02d:%02d", hours, minutes, seconds);

	WriteBuffer(offsetX, offsetY, buffer, 15); // 콘솔에 출력, 색은 15 (흰색) 예시
}

