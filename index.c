#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int text(int x, int y)
{
    printf("\033[%d;%df", x, y);
    return 0;
}

int name()
{
    printf("대충 스토리다");

    return 0;
}

int frame()
{
    //window;
    text(2, 0);
    printf("┌");
    for (int i = 0; i < 98; i++)
    {
        printf("─");
    }
    printf("┐");
    for (int i = 3; i < 30; i++)
    {
        text(i, 0);
        printf("│");
        text(i, 100);
        printf("│");
    }

    text(30, 0);
    printf("└");
    for (int i = 0; i < 98; i++)
    {
        printf("─");
    }
    printf("┘");

    return 0;
}

int title()
{
    text(10, 35);
    printf("아직은 이름 없는 퀴즈게임");
    text(20, 27);
    printf("창을 적절히 조절 후 스페이스 바를 누르세요");
    text(29,2);
    printf("Game Development Dept.");
    text(31, 0);

    return 0;
}

int gamestart()
{
    while (1)
    {
        char key = _getch();
        if (key == 'a')
        {
            storyOne();
            return 0;
        }
    }
}

int main()
{
    frame();
    title();
    gamestart();

    return 0;
}