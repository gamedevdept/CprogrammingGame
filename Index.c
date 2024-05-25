#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

void text(int x, int y) // �ؽ�Ʈ ��ġ�� �����ϴ� �Լ��Դϴ�. ���� ������ �������� �ʾƵ� �˴ϴ�.
{
	COORD Cur;

	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int frame()
{
    system("title ���� ����");
    system("mode con: cols=200 lines=100");
    //window;
    text(0, 0);
    printf("��");

    for (int i = 0; i < 99; i++)
    {
        printf("��");
    }
    printf("��");

    for (int i = 1; i < 50; i++)
    {
        text(0, i);
        printf("��");
        text(100, i);
        printf("��");
    }
    text(0, 48);
    printf("��");
    for (int i = 0; i < 99; i++)
    {
        printf("��");

    }
    printf("��");
    text(0, 50);
    printf("��");
    for (int i = 0; i < 99; i++)
    {
        printf("��");
    }
    printf("��");
    return 0;
}

int title()
{
    text(35, 10);
    printf("������ �̸� ���� �������");
    text(27, 20);
    printf("â�� ������ ���� �� �����̽� �ٸ� ��������");
    text(2, 49);
    printf("Game Development Dept.");
    text(1, 49);

    return 0;
}

void consoleLine()
{
    text(0, 40);
    printf("��");
    for (int i = 0; i < 99; i++)
    {
        printf("��");

    }
    printf("��");

}

void consoleClear()
{
    for (int j = 41; j <= 47; j++)
    {
        text(1, j);
        for (int i = 1; i <= 99; i++)
        {
            printf(" ");
        }

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

void inputClear()
{
    text(1, 49);
    for (int i = 1; i < 100; i++)
    {
        printf(" ");
    }
}

int quizOne()
{
    char answer[100];
    consoleClear();
    text(1, 41);
    printf("����ũ���� ã�Ҵ�.\n");
    text(1, 42);
    printf("����ũ���� ������ ���� �ǳٴ�.\n");
    text(1, 43);
    printf("��ħ���� �� �߷�, ���ɿ��� �� �߷�, ���ῡ�� �� �߷� �ȴ� ����?");
    text(1, 49);
    scanf("%s", &answer);

    if (strncmp("���", answer, 4) == 0 || strncmp("�ΰ�", answer, 4) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int quizTwo()
{
    char answer[100];
    consoleClear();
    text(1, 41);
    printf("����ũ���� ã�Ҵ�. ���� Ŀ���� �ʾҳ�?\n");
    text(1, 42);
    printf("����ũ���� ������ ���� �ǳٴ�.\n");
    text(1, 43);
    printf("��ħ���� �� �߷�, ���ɿ��� �� �߷�, ���ῡ�� �� �߷� �ȴ� ����?");
    text(1, 49);
    scanf("%s", &answer);

    if (strncmp("���", answer, 4) == 0 || strncmp("�ΰ�", answer, 4) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void storyOne()
{
    char line[1024];
    FILE* storyFile;

    consoleLine();
    storyFile = fopen("storyPrologue.txt", "r");
    if (storyFile == NULL)
    {
        printf("���丮 ������ �������� �ʽ��ϴ�. ���丮 ������ �߰��ϼ���.");
        return -1;
    }

    while (fgets(line, 1024, storyFile) != NULL)
    {
        consoleClear();
        text(1, 41);
        printf("%s", line);
        text(1, 49);
        printf("�����̽� �ٸ� ���� ���丮 ����");
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
}
void storyTwo()
{
    char line[1024];
    FILE* storyFile;

    consoleClear();
    storyFile = fopen("storyTwo.txt", "r");
    if (storyFile == NULL)
    {
        printf("���丮 ������ �������� �ʽ��ϴ�. ���丮 ������ �߰��ϼ���.");
        return -1;
    }

    while (fgets(line, 1024, storyFile) != NULL)
    {
        consoleClear();
        text(1, 41);
        printf("%s", line);
        text(1, 49);
        printf("�����̽� �ٸ� ���� ���丮 ����");
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
}

int main()
{
    int getFirstKey = 0;
    int getSecondKey = 0;
    int playerx = 1;
    int playery = 1;
    int keyx = 0;
    int keyy = 0;
    int doorX = 0;
    int doorY = 0;
    int playerStartX = 0;
    int playerStartY = 0;

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
    storyOne();

    

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
        {'w', ' ', ' ', ' ', ' ', 'w', ' ', ' ', ' ', 'e'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}
    };
    inputClear();
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
            else if (map[i][j] == 'e')
            {
                printf("\033[42m \033[0m");
                doorX = j;
                doorY = i;
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
                    map[playery][playerx] = 'p';
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
                    map[playery][playerx] = 'p';
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
                    map[playery][playerx] = 'p';
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
                    map[playery][playerx] = 'p';
                    text(playerx + 80, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        if (keyx == playerx && keyy == playery && getSecondKey == 0)
        {
            int success = 0;
            while (1)
            {
                success = quizOne();

                if (success == 1)
                {
                    text(1, 44);
                    printf("���踦 �����!");
                    getFirstKey = 1;
                    break;
                }
                else
                {
                    text(1, 44);
                    printf("Ʋ�� ���� ���ߴ�. ����ũ���� ȭ�� ����.");
                    text(1, 45);
                    printf("�ϴ� �����ߴٰ� �ٽ� �õ�����.");
                }
            }
        }
        if (doorX == playerx && doorY == playery && getFirstKey == 1)
        {
            storyTwo();
            break;
        }
    }
    clearScreen();
    char mapTwo[20][20] =
    {
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
        {'w', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', ' ', ' ', ' ', ' ', ' ', 'w', 'w', 'w', 'w', 'w', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' ', ' ', 'w', ' ', 'w', ' ', 'w', ' ', ' ', ' ', ' ', ' ', 'w'},
        {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' ', ' ', 'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', 'w', 'w', 'w', ' ', 'w', ' ', ' ', 'w', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', ' ', ' ', 'w', ' ', ' ', 'w', ' ', 'w', 'w', 'w', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', ' ', 'w', 'w', ' ', ' ', 'w', ' ', ' ', ' ', ' ', 'w', ' ', ' ', 'w', ' ', ' ', ' ', 'w'},
        {'w', ' ', ' ', 'w', ' ', ' ', ' ', 'w', ' ', ' ', ' ', ' ', 'w', ' ', ' ', 'w', ' ', ' ', 'w', 'w'},
        {'w', ' ', ' ', ' ', ' ', 'w', 'w', 'w', 'w', 'w', 'w', 'w', ' ', ' ', ' ', 'w', ' ', ' ', 'w', 'w'},
        {'w', ' ', 'w', 'w', 'w', 'w', ' ', ' ', ' ', 'w', 'k', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', 'w'},
        {'w', ' ', ' ', ' ', ' ', 'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', 'w', ' ', 'w', 'w'},
        {'w', ' ', 'w', 'w', ' ', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', 'w'},
        {'w', ' ', ' ', 'w', ' ', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', ' ', ' ', ' ', 'w', 'w', ' ', 'w'},
        {'w', ' ', ' ', 'w', ' ', 'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w'},
        {'w', ' ', ' ', 'w', ' ', ' ', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', ' ', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
        {'w', ' ', ' ', ' ', 'w', ' ', ' ', 'w', ' ', ' ', ' ', 'w', 'w', 'w', ' ', 'w', ' ', 'w', 'w', 'w'},
        {'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'e'},
        {'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}
    };
    inputClear();
    text(70, 5);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (mapTwo[i][j] == 'w')
            {
                printf("\033[41m \033[0m");
            }
            else if (mapTwo[i][j] == ' ')
            {
                printf("\033[0m \033[0m");
            }
            else if (mapTwo[i][j] == 'p')
            {
                printf("\033[44m \033[0m");
                playerStartX = j;
                playerStartY = i;
            }
            else if (mapTwo[i][j] == 'k')
            {
                printf("\033[43m \033[0m");
                keyy = i;
                keyx = j;
            }
            else if (mapTwo[i][j] == 'e')
            {
                printf("\033[42m \033[0m");
                doorX = j;
                doorY = i;
            }
        }
        text(70, 6 + i);
    }

    while (1)
    {
        char key = _getch();
        if (key == 'w' || key == 'W')
        {
            if (playery >= 1)
            {
                if (mapTwo[playery - 1][playerx] != 'w')
                {
                    mapTwo[playery][playerx] = " ";
                    text(playerx + 70, playery + 5);
                    printf("\033[0m ");
                    playery--;
                    mapTwo[playery][playerx] = 'p';
                    text(playerx + 70, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        else if (key == 'a' || key == 'A')
        {
            if (playery >= 1)
            {
                if (mapTwo[playery][playerx - 1] != 'w')
                {
                    mapTwo[playery][playerx] = " ";
                    text(playerx + 70, playery + 5);
                    printf("\033[0m ");
                    playerx--;
                    mapTwo[playery][playerx] = 'p';
                    text(playerx + 70, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        else if (key == 'S' || key == 's')
        {
            if (playery < 19)
            {
                if (mapTwo[playery + 1][playerx] != 'w')
                {
                    mapTwo[playery][playerx] = " ";
                    text(playerx + 70, playery + 5);
                    printf("\033[0m ");
                    playery++;
                    mapTwo[playery][playerx] = 'p';
                    text(playerx + 70, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        else if (key == 'd' || key == 'D')
        {
            if (playerx < 19)
            {
                if (mapTwo[playery][playerx + 1] != 'w')
                {
                    mapTwo[playery][playerx] = " ";
                    text(playerx + 70, playery + 5);
                    printf("\033[0m ");
                    playerx++;
                    mapTwo[playery][playerx] = 'p';
                    text(playerx + 70, playery + 5);
                    printf("\033[44m \033[0m");
                }
            }
        }
        if (keyx == playerx && keyy == playery && getFirstKey == 0)
        {
            int success = 0;
            while (1)
            {
                success = quizOne();

                if (success == 1)
                {
                    text(1, 44);
                    printf("���踦 �����!");
                    getFirstKey = 1;
                    break;
                }
                else
                {
                    text(1, 44);
                    printf("Ʋ�� ���� ���ߴ�. ����ũ���� ȭ�� ����.");
                    text(1, 45);
                    printf("�ϴ� �����ߴٰ� �ٽ� �õ�����.");
                }
            }
        }
        if (doorX == playerx && doorY == playery && getFirstKey == 1)
        {
            storyTwo();
            break;
        }
    }

    return 0;
}