#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include <thread>

void gotoxy(int,int);
void draw_ship(int x,int y);
void draw_bullet(int x, int y);
void erase_ship (int x, int y);
void erase_bullet (int x, int y);
void setcursor(bool visible);
void setcolor(int fg,int bg);
char cursor(int x, int y);
void gen_star();
int random(int lower, int upper);

int main()
{
    char ch='.';
    char direction = '.';
    char shoot = '.';
    int x=38,y=20;
    int count = -1;
    int check = 0;
    int x_bullet[10] = {-1,-1,-1,-1,-1,-1}, y_bullet[10] = {-1,-1,-1,-1,-1,-1};
    setcursor(0);
    srand( time( NULL ) );
    gen_star(20);
    draw_ship(x,y);
    do
    {
        if (kbhit())
        {
            ch=getch();
            if(ch=='a')
            {
                direction = 'L'; //Left
            }
            if(ch=='d')
            {
                direction = 'R'; //Right
            }
            if(ch=='s')
            {
                direction = 'P'; //Pause
            }
            if((ch==' ') && (check < 5))
            {
                check++;
                if (x_bullet[0] == -1)
                {
                    count = 0;
                }
                else if (x_bullet[1] == -1)
                {
                    count = 1;
                }
                else if (x_bullet[2] == -1)
                {
                    count = 2;
                }
                else if (x_bullet[3] == -1)
                {
                    count = 3;
                }
                else if (x_bullet[4] == -1)
                {
                    count = 4;
                }
                x_bullet[count] = x + 3;
                y_bullet[count] = y - 1;
                shoot = 'S'; //Shoot
            }
            fflush(stdin);
        }
        if (direction != '.')
        {
            if (direction == 'L')
            {
                draw_ship(--x,y);
                erase_ship(x + 8, y);
                if (x <= 0)
                {
                    x++;
                }
            }
            if (direction == 'R')
            {
                draw_ship(++x,y);
                erase_ship(x - 2, y);
                if (x >= 80)
                {
                    x--;
                }
            }
            if (direction == 'P')
            {
                direction = ' ';
            }
            if (shoot == 'S')
            {
                if (x_bullet[0] != -1)
                {
                    draw_bullet(x_bullet[0], --y_bullet[0]);
                    erase_bullet(x_bullet[0], y_bullet[0] + 1);
                    if (y_bullet[0] == 0)
                    {
                        --check;
                        erase_bullet(x_bullet[0], 0);
                        x_bullet[0] = -1;
                    }
                    if (cursor(x_bullet[0],y_bullet[0]-1) == '*')
                    {
                        erase_bullet(x_bullet[0], y_bullet[0]-1);
                        erase_bullet(x_bullet[0], y_bullet[0]);
                        x_bullet[0] = -1;
                        std::thread q(Beep, 700, 500);
                        q.detach();
                    }
                }
                if (x_bullet[1] != -1)
                {
                    draw_bullet(x_bullet[1], --y_bullet[1]);
                    erase_bullet(x_bullet[1], y_bullet[1] + 1);
                    if (y_bullet[1] == 0)
                    {
                        --check;
                        erase_bullet(x_bullet[1], 0);
                        x_bullet[1] = -1;
                    }
                    if (cursor(x_bullet[1],y_bullet[1]-1) == '*')
                    {
                        erase_bullet(x_bullet[1], y_bullet[1]-1);
                        erase_bullet(x_bullet[1], y_bullet[1]);
                        x_bullet[1] = -1;
                        std::thread q(Beep, 700, 500);
                        q.detach();
                    }
                }
                if (x_bullet[2] != -1)
                {
                    draw_bullet(x_bullet[2], --y_bullet[2]);
                    erase_bullet(x_bullet[2], y_bullet[2] + 1);
                    if (y_bullet[2] == 0)
                    {
                        --check;
                        erase_bullet(x_bullet[2], 0);
                        x_bullet[2] = -1;
                    }
                    if (cursor(x_bullet[2],y_bullet[2]-1) == '*')
                    {
                        erase_bullet(x_bullet[2], y_bullet[2]-1);
                        erase_bullet(x_bullet[2], y_bullet[2]);
                        x_bullet[2] = -1;
                        std::thread q(Beep, 700, 500);
                        q.detach();
                    }
                }
                if (x_bullet[3] != -1)
                {
                    draw_bullet(x_bullet[3], --y_bullet[3]);
                    erase_bullet(x_bullet[3], y_bullet[3] + 1);
                    if (y_bullet[3] == 0)
                    {
                        --check;
                        erase_bullet(x_bullet[3], 0);
                        x_bullet[3] = -1;
                    }
                    if (cursor(x_bullet[3],y_bullet[0]-1) == '*')
                    {
                        erase_bullet(x_bullet[3], y_bullet[3]-1);
                        erase_bullet(x_bullet[3], y_bullet[3]);
                        x_bullet[3] = -1;
                        std::thread q(Beep, 700, 500);
                        q.detach();
                    }
                }
                if (x_bullet[4] != -1)
                {
                    draw_bullet(x_bullet[4], --y_bullet[4]);
                    erase_bullet(x_bullet[4], y_bullet[4] + 1);
                    if (y_bullet[4] == 0)
                    {
                        --check;
                        erase_bullet(x_bullet[4], 0);
                        x_bullet[4] = -1;
                    }
                    if (cursor(x_bullet[4],y_bullet[4]-1) == '*')
                    {
                        erase_bullet(x_bullet[4], y_bullet[4]-1);
                        erase_bullet(x_bullet[4], y_bullet[4]);
                        x_bullet[4] = -1;
                        std::thread q(Beep, 700, 500);
                        q.detach();
                    }
                }
            }
        }
        Sleep(100);
    }
    while (ch!='x');
    return 0;
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
    gotoxy(x,y);
    setcolor(2, 4);
    printf(" <-0-> ");
}
void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(8, 9);
    printf("|");
}
void erase_ship (int x, int y)
{
    setcolor(0, 0);
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" ");
}
void erase_bullet (int x, int y)
{
    setcolor(0, 0);
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" ");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void setcolor(int fg,int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x,y};
    DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}
void gen_star(int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = random(10, 70);
        int y = random(2, 5);
        gotoxy(x, y);
        printf("*");
    }
}
int random(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
