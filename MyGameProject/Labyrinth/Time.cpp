#include "Time.h"

void Time::Start()		// 시작시간
{
	startTime = chrono::steady_clock::now();
}

void Time::End()		// 종료 시간
{
	endTime = chrono::steady_clock::now();
}

int Time::GetElapsedSeconds() const
{
	auto now = chrono::steady_clock::now();
	return chrono::duration_cast<chrono::seconds>(now - startTime).count();
}

// 플레이타임 보여주는 함수 
void Time::DisplayPlayTime(int offsetX, int offsetY) const
{
	char clear[50] = "                         "; // 길이 충분히 확보
	WriteBuffer(offsetX, offsetY, clear, 0);       // 검은색(0)으로 지우기
	auto now = chrono::steady_clock::now(); // 현재 시간
	int seconds = chrono::duration_cast<chrono::seconds>(now - startTime).count();
	int minutes = seconds / 60;
	int hours = minutes / 60;
	seconds %= 60;
	minutes %= 60;

	char buffer[50];
	sprintf_s(buffer, "Play Time: %02d:%02d:%02d", hours, minutes, seconds);

	WriteBuffer(offsetX, offsetY, buffer, 15); // 콘솔에 출력, 색은 15 (흰색) 예시
}

