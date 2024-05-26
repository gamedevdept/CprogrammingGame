#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

int KEYINPUT() {
    keybd_event(VK_HANGEUL, 0, 0, 0);//누름

    keybd_event(VK_HANGEUL, 0, KEYEVENTF_KEYUP, 0);// 누름 해제

    return 0;
}

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
    printf("스핑크스를 찾았다.\n");
    text(1, 42);
    printf("스핑크스가 나에게 말을 건넨다.\n");
    text(1, 43);
    printf("아침에는 네 발로, 점심에는 두 발로, 저녁에는 세 발로 걷는 것은?");
    text(1, 49);
    scanf("%s", &answer);
    KEYINPUT();

    if (strncmp("사람", answer, 4) == 0 || strncmp("인간", answer, 4) == 0)
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
    printf("스핑크스를 찾았다. 조금 커지지 않았나?");
    text(1, 42);
    printf("스핑크스가 나에게 말을 건넨다.");
    text(1, 43);
    printf("살아있지만 공기를 내뿜지 않는다. 살아있어도 죽은 듯이 차갑다.");
    text(1, 44);
    printf("절대 목마르지 않지만 항상 마신다. 이것은 무엇인가?");
    text(1, 49);
    scanf("%s", &answer);
    KEYINPUT();

    if (strncmp("물고기", answer, 6) == 0 || strncmp("생선", answer, 4) == 0)
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
    printf("거대한 스핑크스가 문제를 낸다.");
    text(1, 42);
    printf("모든 문제를 맞추어 스핑크스를 이기자.");
    text(1, 49);
    printf("스페이스 바를 눌러 퀴즈 시작");
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
    printf("현재 1번 문제 | HP : 3");

    while (1)
    {
        text(1, 41);
        printf("거대하지만 절대 성장하지 않고, 뿌리가 있지만 드러나지 않으며,");
        text(1, 42);
        printf("나무보다 큰 것은?");
        text(1, 49);
        scanf("%s", &answer);
        if (strncmp("산", answer, 2) == 0)
        {
            correct++;
            life = 3;
            inputClear();
            consoleClear();
            text(1, 41);
            printf("정답을 맞추고 말았다.");
            text(1, 42);
            printf("스핑크스는 머리부터 녹아내린다.");
            text(1, 49);
            printf("스페이스 바를 눌러 계속 진행");
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
            printf("아무래도 틀린 듯 하다...");
            text(1, 42);
            printf("생명력이 1 감소했다.");
            text(1, 39);
            printf("현재 1번 문제 | HP : %d", life);
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
            printf("스핑크스 : 틀렸다. 너는 나의 제물이 될 것이다.");
            text(1, 42);
            printf("그 많은 기회를 전부 소진하다니, 너의 최후로는 딱이군.");
            text(1, 43);
            printf("당신은 스핑크스의 제물이 되었습니다.");
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
        printf("현재 2번 문제 | HP : %d", life);
        text(1, 41);
        printf("봄에는 화사하게 차려입고, 여름에는 옷을 껴입으며,");
        text(1, 42);
        printf("추워지기 시작하면 옷을 벗어던지고, 겨울이 되면 벌거숭이가 된다.");
        text(1, 43);
        printf("이것은 무엇인가?");
        text(1, 49);
        scanf("%s", &answer);
        if (strncmp("나무", answer, 4) == 0)
        {
            correct++;
            life = 3;
            inputClear();
            consoleClear();
            text(1, 41);
            printf("정답을 맞추고 말았다.");
            text(1, 42);
            printf("스핑크스의 왼쪽 팔이 녹아내린다.");
            text(1, 49);
            printf("스페이스 바를 눌러 계속 진행");
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
            printf("아무래도 틀린 듯 하다...");
            text(1, 42);
            printf("생명력이 1 감소했다");
            text(1, 39);
            printf("현재 2번 문제 | HP : %d", life);
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
            printf("현재 %d번 문제 | HP : %d", correct, life);
            text(1, 41);
            printf("스핑크스 : 틀렸다. 너는 나의 제물이 될 것이다.");
            text(1, 42);
            printf("그 많은 기회를 전부 소진하다니, 너의 최후로는 딱이군.");
            text(1, 43);
            printf("당신은 스핑크스의 제물이 되었습니다.");
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
        printf("현재 %d번 문제 | HP : %d", correct, life);
        text(1, 41);
        printf("낮에는 모두에게 자신의 존재를 알리다가, 밤이 되면 흔적 없이 숨어버리는 것은?");
        text(1, 49);
        scanf("%s", &answer);
        if (strncmp("태양", answer, 4) == 0 || strncmp("해", answer, 2) == 0)
        {
            correct++;
            life = 3;
            consoleClear();
            text(1, 41);
            printf("정답을 맞추고 말았다.");
            text(1, 42);
            printf("스핑크스의 오른쪽 팔이 녹아내린다.");
            text(1, 49);
            printf("스페이스 바를 눌러 계속 진행");
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
            printf("아무래도 틀린 듯 하다...");
            text(1, 42);
            printf("생명력이 1 감소했다");
            text(1, 39);
            printf("현재 %d번 문제 | HP : %d", correct, life);
        }
        if (life == 0)
        {
            inputClear();
            consoleClear();
            text(1, 39);
            printf("현재 %d번 문제 | HP : %d", correct, life);
            text(1, 41);
            printf("스핑크스 : 틀렸다. 너는 나의 제물이 될 것이다.");
            text(1, 42);
            printf("그 많은 기회를 전부 소진하다니, 너의 최후로는 딱이군.");
            text(1, 43);
            printf("당신은 스핑크스의 제물이 되었습니다.");
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
}

void storyTwo()
{
    char line[1024];
    FILE* storyFile;

    consoleClear();
    storyFile = fopen("storyTwo.txt", "r");
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
}

void storyThree()
{
    char line[1024];
    FILE* storyFile;

    consoleClear();
    storyFile = fopen("storyThree.txt", "r");
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
}

void storyFour()
{
    char line[1024];
    FILE* storyFile;

    consoleClear();
    storyFile = fopen("storyFour.txt", "r");
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
    printf("벽 : \033[41m \033[0m 플레이어 : \033[44m \033[0m 유물 : \033[43m \033[0m 탈출구 : \033[42m \033[0m");
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

                printf("유물 '매 모양의 호루스' 를 얻었다!");
                getFirstKey = 1;
            }
            else
            {
                consoleClear();
                text(1, 41);
                printf("틀린 답을 말했다. 스핑크스는 화가 났다.");
                text(1, 42);
                printf("일단 후퇴했다가 다시 시도하자.");
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
            printf("잠긴 문이다. 무언가 열 도구가 있을 것이다.");
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
    printf("벽 : \033[41m \033[0m 플레이어 : \033[44m \033[0m 유물 : \033[43m \033[0m 탈출구 : \033[42m \033[0m");
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
                printf("유물 '오시리스의 동상'을 얻었다!");
                getSecondKey = 1;
            }
            else
            {
                consoleClear();
                text(1, 41);
                printf("틀린 답을 말했다. 스핑크스는 화가 났다.");
                text(1, 42);
                printf("일단 후퇴했다가 다시 시도하자.");
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
            printf("잠긴 문이다. 동상을 올려놓는 선반이 있다.");
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
        printf("상명대학교 게임전공 2024년 1학기");
        text(1, 2);
        printf("C프로그래밍 기말과제");
        text(1, 3);
        printf("김성현, 김태연, 임초연, 김영찬");
        text(1, 51);
    }

    miku();

    return 0;
}