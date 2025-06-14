#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main() 
{
    int y = 0;  // 화살표 Y 위치
    char dir = '→';  // 방향

    while (true) 
    {
        system("cls");

        // 화살표 출력
        for (int i = 0; i < y; i++) printf("\n");
        printf("%c", dir);

        // 입력 처리
        if (_kbhit()) 
        {
            char key = _getch();
            if (key == -32) key = _getch();  // 방향키 처리

            if (key == 75 && dir == '←') 
            {  // 왼쪽 화살표
                printf("\n성공!");
                break;
            }
        }

        y++;
        Sleep(500);  // 0.5초마다 이동
        if (y > 10) break;  // 화면 끝 도달
    }
    return 0;
}
