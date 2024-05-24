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

int quizOne()
{
    char answer[100];
    printf("스핑크스를 찾았다.\n");
    printf("스핑크스가 나에게 말을 건넨다.\n");
    printf("아침에는 네 발로, 점심에는 두 발로, 저녁에는 세 발로 걷는 것은?");

    scanf("%s", &answer);

    if (answer == "사람" || answer == "인간")
    {
        return 1;
    }
    else
    {
        return 0;
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
    storyFile = fopen("C:\\Icebox\\storyPrologue.txt", "r");
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
    int keyx = 0;
    int keyy = 0;
    char map[10][10] =
    {
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'w', 'p', ' ', ' ', 'w', ' ', ' ', ' ', ' ', 'w'},
        {'w', ' ', 'w', ' ', ' ', ' ', 'w', 'w', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', ' ', 'k', 'w', ' ', 'w'},
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
            else if (map[i][j] == 'k')
            {
                printf("\033[43m \033[0m");
                keyy = i;
                keyx = j;
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
        if (key == 'w' || key == 'W')
        {
            if (playery >= 1)
            {
                if (map[playery - 1][playerx] != 'w')
                {
                    map[playery][playerx] = " ";
                    text(playerx + 80, playery + 5);
                    printf("\033[0m ");
                    playery--;
                    map[playery][playerx] = 'w';
                    text(playerx + 80, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        else if (key == 'a' || key == 'A')
        {
            if (playery >= 1)
            {
                if (map[playery][playerx - 1] != 'w')
                {
                    map[playery][playerx] = " ";
                    text(playerx + 80, playery + 5);
                    printf("\033[0m ");
                    playerx--;
                    map[playery][playerx] = 'w';
                    text(playerx + 80, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        else if (key == 'S' || key == 's')
        {
            if (playery < 9)
            {
                if (map[playery + 1][playerx] != 'w')
                {
                    map[playery][playerx] = " ";
                    text(playerx + 80, playery + 5);
                    printf("\033[0m ");
                    playery++;
                    map[playery][playerx] = 'w';
                    text(playerx + 80, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        else if (key == 'd' || key == 'D')
        {
            if (playerx < 9)
            {
                if (map[playery][playerx + 1] != 'w')
                {
                    map[playery][playerx] = " ";
                    text(playerx + 80, playery + 5);
                    printf("\033[0m ");
                    playerx++;
                    map[playery][playerx] = 'w';
                    text(playerx + 80, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        if (keyx == playerx && keyy == playery)
        {
            int success = 0;
            while (1)
            {
                success = quizOne();

                if (success == 1)
                {
                    printf("열쇠를 얻었다!");
                    break;
                }
                else
                {
                    printf("틀린 답을 말했다. 스핑크스는 화가 났다.");
                    printf("일단 후퇴했다가 다시 시도하자.");
                }
            }
        }
    }
    clearScreen();

    return 0;
}