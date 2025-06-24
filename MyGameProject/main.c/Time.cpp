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

void CountDown()
{
	for (int i = 3; i > 0; --i)
	{
		ClearBuffer();
		WriteBuffer(45, 30, "다음 스테이지로 넘어갑니다...", 8);  // 잔상 해결해야하는데 
		char countdown[10];			// 나중에 string으로 바꿔서 적용하기
		// 정수를 문자열로 변환해서 버퍼에 저장하는 함수 (버퍼 오버플로우 방지용으로 _s 사용)
		sprintf_s(countdown, "%d", i);	// 버퍼랑 관련된 함수로 이걸 써야 변환이 된다.
		WriteBuffer(/*35, 12*/61, 30, "   ", 14);  // 숫자 지울 공간 확보 -> 절반 해결 
		WriteBuffer(61, 30, countdown, 15);
		//ClearBuffer();
		FlipBuffer();



		//FlipBuffer();
		Sleep(1000);		// 여기선 Sleep을 무조건 써야함 -> 시간 제어 해주는거 
	}
	ClearBuffer();	// 다시 초기화
}
