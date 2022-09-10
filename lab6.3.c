#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
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
    setcolor(7, 0);
    printf("   |   ");
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
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("      ");
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
int main()
{
    char ch='.';
    char direction = '.';
    char shoot = '.';
    int x=38,y=20;
    int count = 0;
    int x_bullet, y_bullet;
    setcursor(0);
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
            if((ch==' ') && (shoot=='.'))
            {
                x_bullet = x;
                y_bullet = y - 1;
                count++;
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
                direction = '.';
            }
            if (shoot == 'S')
            {
                if (y_bullet == 0)
                {
                    erase_bullet(x_bullet, 0);
                    shoot = '.';
                }
                else
                {
                    draw_bullet(x_bullet, --y_bullet);
                    erase_bullet(x_bullet, y_bullet + 1);
                }
            }
        }
        Sleep(100);
    }
    while (ch!='x');
    return 0;
}
