#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

void text(int x, int y) // 텍스트 위치를 조정하는 함수입니다. 버그 없으니 수정하지 않아도 됩니다.
{
	COORD Cur;

	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int frame()
{
    system("title 퀴즈 게임");
    system("mode con: cols=200 lines=100");
    //window;
    text(0, 0);
    printf("┌");

    for (int i = 0; i < 99; i++)
    {
        printf("─");
    }
    printf("┐");

    for (int i = 1; i < 50; i++)
    {
        text(0, i);
        printf("│");
        text(100, i);
        printf("│");
    }
    text(0, 48);
    printf("├");
    for (int i = 0; i < 99; i++)
    {
        printf("─");

    }
    printf("┤");
    text(0, 50);
    printf("└");
    for (int i = 0; i < 99; i++)
    {
        printf("─");
    }
    printf("┘");
    return 0;
}

int title()
{
    text(35, 10);
    printf("아직은 이름 없는 퀴즈게임");
    text(27, 20);
    printf("창을 적절히 조절 후 스페이스 바를 누르세요");
    text(2, 49);
    printf("Game Development Dept.");
    text(1, 49);

    return 0;
}

void consoleLine()
{
    text(0, 40);
    printf("├");
    for (int i = 0; i < 99; i++)
    {
        printf("─");

    }
    printf("┤");

}

void consoleClear()
{
    text(1, 41);
    for (int i = 1; i <= 99; i++)
    {
        printf(" ");
    }
}

void clearScreen()
{
    for (int i = 1; i <= 39; i++)
    {
        for (int j = 1; j <= 99; j++)
        {
            text(j, i);
            printf(" ");
        }
    }
}

int main()
{
    frame();
    title();
    while (1)
    {
        char key = _getch();
        if (key == ' ')
        {
            clearScreen();
            break;
        }
    }

    char line[1024];
    FILE* storyFile;

    consoleLine();
    storyFile = fopen("D:\\Icebox\\C11\\storyPrologue.txt", "r");
    if (storyFile == NULL)
    {
        printf("스토리 파일이 존재하지 않습니다. 스토리 파일을 추가하세요.");
        return -1;
    }

    while (fgets(line, 1024, storyFile) != NULL)
    {
        consoleClear();
        text(1, 41);
        printf("%s", line);
        text(1, 49);
        printf("스페이스 바를 눌러 스토리 진행");
        while (1)
        {
            text(0, 51);
            char key = _getch();
            if (key == ' ')
            {
                consoleClear();
                text(1, 41);
                printf("%s", line);
                break;
            }
        }
    }

    int playerx = 1;
    int playery = 1;
    char map[10][10] =
    {
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'w', 'p', ' ', ' ', 'w', ' ', ' ', ' ', ' ', 'w'},
        {'w', ' ', 'w', ' ', ' ', ' ', 'w', 'w', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', ' ', 't', 'w', ' ', 'w'},
        {'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w'},
        {'w', ' ', 'w', ' ', ' ', ' ', ' ', 'w', ' ', 'w'},
        {'w', ' ', 'w', ' ', ' ', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', ' ', ' ', ' ', 'w', ' ', ' ', ' ', ' '},
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'e'}
    };

    text(80, 5);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 'w')
            {
                printf("\033[41m \033[0m");
            }
            else if (map[i][j] == ' ')
            {
                printf("\033[0m \033[0m");
            }
            else if (map[i][j] == 'p')
            {
                printf("\033[44m \033[0m");
            }
            else if (map[i][j] == 't')
            {
                printf("\033[43m \033[0m");
            }
            else
            {
                printf("\033[42m \033[0m");
            }
        }
        text(80, 6 + i); 
    }

    while (1)
    {
        char key = _getch();
        if (key == 'w' || 'W')
        {
            if (playery >= 1)
            {
                if (map[playery + 1][playerx] != 'w')
                {
                    map[playery][playerx] = " ";
                    playery++;
                    map[playery][playerx] = 'w';
                }
            }
        }
        else if (key == 'a' || 'A')
        {
            if (playery >= 1)
            {
                if (map[playery][playerx - 1] != 'w')
                {
                    map[playery][playerx] = " ";
                    playerx--;
                    map[playery][playerx] = 'w';
                }
            }
        }
        else if (key == 'S' || 's')
        {
            if (playery < 9)
            {
                if (map[playery - 1][playerx] != 'w')
                {
                    map[playery][playerx] = " ";
                    playery--;
                    map[playery][playerx] = 'w';
                }
            }
        }
        else if (key == 'd' || 'D')
        {
            if (playerx < 9)
            {
                if (map[playery][playerx + 1] != 'w')
                {
                    map[playery][playerx] = " ";
                    playerx++;
                    map[playery][playerx] = 'w';
                }
            }
        }
    }
    return 0;
}