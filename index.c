#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

int KEYINPUT() {
    keybd_event(VK_HANGEUL, 0, 0, 0);//����

    keybd_event(VK_HANGEUL, 0, KEYEVENTF_KEYUP, 0);// ���� ����

    return 0;
}

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
    KEYINPUT();

    if (strncmp("���", answer, 4) == 0 || strncmp("�ΰ�", answer, 4) == 0)
    {
        return 1;
    }
    else
    {
        KEYINPUT();
        inputClear();
        return 0;
    }
}

int quizTwo()
{
    char answer[100];
    consoleClear();
    text(1, 41);
    printf("����ũ���� ã�Ҵ�. ���� Ŀ���� �ʾҳ�?");
    text(1, 42);
    printf("����ũ���� ������ ���� �ǳٴ�.");
    text(1, 43);
    printf("��������� ���⸦ ������ �ʴ´�. ����־ ���� ���� ������.");
    text(1, 44);
    printf("���� �񸶸��� ������ �׻� ���Ŵ�. �̰��� �����ΰ�?");
    text(1, 49);
    scanf("%s", &answer);
    KEYINPUT();

    if (strncmp("�����", answer, 6) == 0 || strncmp("����", answer, 4) == 0)
    {
        return 1;
    }
    else
    {
        KEYINPUT();
        inputClear();
        return 0;
    }
}

int quizThree()
{
    inputClear();
    consoleClear();
    text(1, 41);
    printf("�Ŵ��� ����ũ���� ������ ����.");
    text(1, 42);
    printf("��� ������ ���߾� ����ũ���� �̱���.");
    text(1, 49);
    printf("�����̽� �ٸ� ���� ���� ����");
    while (1)
    {
        char key = _getch();
        if (key == ' ')
        {
            break;
        }
    }
    char answer[100];
    int correct = 1;
    int life = 3;
    inputClear();
    consoleClear();
    text(1, 39);
    printf("���� 1�� ���� | HP : 3");

    while (1)
    {
        text(1, 41);
        printf("�Ŵ������� ���� �������� �ʰ�, �Ѹ��� ������ �巯���� ������,");
        text(1, 42);
        printf("�������� ū ����?");
        text(1, 49);
        scanf("%s", &answer);
        if (strncmp("��", answer, 2) == 0)
        {
            correct++;
            life = 3;
            inputClear();
            consoleClear();
            text(1, 41);
            printf("������ ���߰� ���Ҵ�.");
            text(1, 42);
            printf("����ũ���� �Ӹ����� ��Ƴ�����.");
            text(1, 49);
            printf("�����̽� �ٸ� ���� ��� ����");
            while (1)
            {
                char key = _getch();
                if (key == ' ')
                {
                    break;
                }

            }
            break;
        }
        else
        {
            life--;
            consoleClear();
            inputClear();
            text(1, 41);
            printf("�ƹ����� Ʋ�� �� �ϴ�...");
            text(1, 42);
            printf("������� 1 �����ߴ�.");
            text(1, 39);
            printf("���� 1�� ���� | HP : %d", life);
            while (1)
            {
                char key = _getch();
                if (key == ' ')
                {
                    break;
                }

            }
        }
        if (life == 0)
        {
            inputClear();
            consoleClear();
            text(1, 41);
            printf("����ũ�� : Ʋ�ȴ�. �ʴ� ���� ������ �� ���̴�.");
            text(1, 42);
            printf("�� ���� ��ȸ�� ���� �����ϴٴ�, ���� ���ķδ� ���̱�.");
            text(1, 43);
            printf("����� ����ũ���� ������ �Ǿ����ϴ�.");
            text(1, 1);
            printf("Game Over");

            return 0;
        }
    }
    while (1)
    {
        inputClear();
        consoleClear();
        text(1, 39);
        printf("���� 2�� ���� | HP : %d", life);
        text(1, 41);
        printf("������ ȭ���ϰ� �����԰�, �������� ���� ��������,");
        text(1, 42);
        printf("�߿����� �����ϸ� ���� ���������, �ܿ��� �Ǹ� ���ż��̰� �ȴ�.");
        text(1, 43);
        printf("�̰��� �����ΰ�?");
        text(1, 49);
        scanf("%s", &answer);
        if (strncmp("����", answer, 4) == 0)
        {
            correct++;
            life = 3;
            inputClear();
            consoleClear();
            text(1, 41);
            printf("������ ���߰� ���Ҵ�.");
            text(1, 42);
            printf("����ũ���� ���� ���� ��Ƴ�����.");
            text(1, 49);
            printf("�����̽� �ٸ� ���� ��� ����");
            while (1)
            {
                char key = _getch();
                if (key == ' ')
                {
                    break;
                }

            }
            break;
        }
        else
        {
            inputClear();
            consoleClear();
            life--;
            text(1, 41);
            printf("�ƹ����� Ʋ�� �� �ϴ�...");
            text(1, 42);
            printf("������� 1 �����ߴ�");
            text(1, 39);
            printf("���� 2�� ���� | HP : %d", life);
            while (1)
            {
                char key = _getch();
                if (key == ' ')
                {
                    break;
                }

            }
        }
        if (life == 0)
        {
            inputClear();
            consoleClear();
            text(1, 39);
            printf("���� %d�� ���� | HP : %d", correct, life);
            text(1, 41);
            printf("����ũ�� : Ʋ�ȴ�. �ʴ� ���� ������ �� ���̴�.");
            text(1, 42);
            printf("�� ���� ��ȸ�� ���� �����ϴٴ�, ���� ���ķδ� ���̱�.");
            text(1, 43);
            printf("����� ����ũ���� ������ �Ǿ����ϴ�.");
            text(1, 1);
            printf("Game Over");

            return 0;
        }
    }
    while (1)
    {
        inputClear();
        consoleClear();
        text(1, 39);
        printf("���� %d�� ���� | HP : %d", correct, life);
        text(1, 41);
        printf("������ ��ο��� �ڽ��� ���縦 �˸��ٰ�, ���� �Ǹ� ���� ���� ��������� ����?");
        text(1, 49);
        scanf("%s", &answer);
        if (strncmp("�¾�", answer, 4) == 0 || strncmp("��", answer, 2) == 0)
        {
            correct++;
            life = 3;
            consoleClear();
            text(1, 41);
            printf("������ ���߰� ���Ҵ�.");
            text(1, 42);
            printf("����ũ���� ������ ���� ��Ƴ�����.");
            text(1, 49);
            printf("�����̽� �ٸ� ���� ��� ����");
            while (1)
            {
                char key = _getch();
                if (key == ' ')
                {
                    return 1;
                }
            }
        }
        else
        {
            life--;
            inputClear();
            consoleClear();
            text(1, 41);
            printf("�ƹ����� Ʋ�� �� �ϴ�...");
            text(1, 42);
            printf("������� 1 �����ߴ�");
            text(1, 39);
            printf("���� %d�� ���� | HP : %d", correct, life);
        }
        if (life == 0)
        {
            inputClear();
            consoleClear();
            text(1, 39);
            printf("���� %d�� ���� | HP : %d", correct, life);
            text(1, 41);
            printf("����ũ�� : Ʋ�ȴ�. �ʴ� ���� ������ �� ���̴�.");
            text(1, 42);
            printf("�� ���� ��ȸ�� ���� �����ϴٴ�, ���� ���ķδ� ���̱�.");
            text(1, 43);
            printf("����� ����ũ���� ������ �Ǿ����ϴ�.");
            text(1, 1);
            printf("Game Over");

            return 0;
        }
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

void storyThree()
{
    char line[1024];
    FILE* storyFile;

    consoleClear();
    storyFile = fopen("storyThree.txt", "r");
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

void storyFour()
{
    char line[1024];
    FILE* storyFile;

    consoleClear();
    storyFile = fopen("storyFour.txt", "r");
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

int miku()
{
    char key = _getch();
    if (key = 'm')
    {
        char line[1024];
        FILE* storyFile;

        consoleLine();
        storyFile = fopen("mikudayo.txt", "r");
        if (storyFile == NULL)
        {
            printf("??");
            return 0;
        }
        int lineNumber = 1;
        while (fgets(line, 1024, storyFile) != NULL)
        {
            consoleClear();
            text(1, lineNumber);
            printf("%s", line);
            lineNumber++;
            text(1, 51);
        }
        return 0;
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
    text(1, 39);
    printf("�� : \033[41m \033[0m �÷��̾� : \033[44m \033[0m ���� : \033[43m \033[0m Ż�ⱸ : \033[42m \033[0m");
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
                playerStartX = j;
                playerStartY = i;
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
        if (keyx == playerx && keyy == playery && getFirstKey == 0)
        {
            int success = 0;
            success = quizOne();

            if (success == 1)
            {
                consoleClear();
                text(1, 41);

                printf("���� '�� ����� ȣ�罺' �� �����!");
                getFirstKey = 1;
            }
            else
            {
                consoleClear();
                text(1, 41);
                printf("Ʋ�� ���� ���ߴ�. ����ũ���� ȭ�� ����.");
                text(1, 42);
                printf("�ϴ� �����ߴٰ� �ٽ� �õ�����.");
                text(playerx + 80, playery + 5);
                printf("\033[0m \033[0m");

                playerx = playerStartX;
                playery = playerStartY;
                text(playerx + 80, playery + 5);
                printf("\033[0m \033[0m");

                text(keyx + 80, keyy + 5);
                printf("\033[43m \033[0m");
            }
        }
        if (doorX == playerx && doorY == playery && getFirstKey == 1)
        {
            clearScreen();
            storyTwo();
            break;
        }
        else if (doorX == playerx && doorY == playery && getFirstKey == 0)
        {
            consoleClear();
            text(1, 41);
            printf("��� ���̴�. ���� �� ������ ���� ���̴�.");
            text(playerx + 80, playery + 5);
            printf("\033[42m \033[0m");

            playerx--;

            text(playerx + 80, playery + 5);
            printf("\033[0m \033[0m");

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
    text(1, 39);
    printf("�� : \033[41m \033[0m �÷��̾� : \033[44m \033[0m ���� : \033[43m \033[0m Ż�ⱸ : \033[42m \033[0m");
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
        if (keyx == playerx && keyy == playery && getSecondKey == 0)
        {
            int success = 0;
            success = quizTwo();

            if (success == 1)
            {
                consoleClear();
                text(1, 41);
                printf("���� '���ø����� ����'�� �����!");
                getSecondKey = 1;
            }
            else
            {
                consoleClear();
                text(1, 41);
                printf("Ʋ�� ���� ���ߴ�. ����ũ���� ȭ�� ����.");
                text(1, 42);
                printf("�ϴ� �����ߴٰ� �ٽ� �õ�����.");
                text(playerx + 70, playery + 5);
                printf("\033[0m \033[0m");

                playerx = playerStartX;
                playery = playerStartY;
                text(playerx + 70, playery + 5);
                printf("\033[0m \033[0m");

                text(keyx + 70, keyy + 5);
                printf("\033[43m \033[0m");
            }
        }
        if (doorX == playerx && doorY == playery && getSecondKey == 1)
        {
            clearScreen();
            storyThree();
            break;
        }
        else if (doorX == playerx && doorY == playery && getSecondKey == 0)
        {
            consoleClear();
            text(1, 41);
            printf("��� ���̴�. ������ �÷����� ������ �ִ�.");
            text(playerx + 70, playery + 5);
            printf("\033[42m \033[0m");

            playerx--;

            text(playerx + 70, playery + 5);
            printf("\033[0m \033[0m");
        }
    }
    int success = 0;
    success = quizThree();
    if (success == 1)
    {
        storyFour();
        text(1, 41);
        consoleClear();
        inputClear();
        text(1, 1);
        printf("�����б� �������� 2024�� 1�б�");
        text(1, 2);
        printf("C���α׷��� �⸻����");
        text(1, 3);
        printf("�輺��, ���¿�, ���ʿ�, �迵��");
        text(1, 51);
    }

    miku();

    return 0;
}