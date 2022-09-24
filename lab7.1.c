#include<stdio.h>
#include<windows.h>
#include<time.h>
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
    printf(" <-0-> ");
}
void draw_bullet(int x,int y)
{
    gotoxy(x,y);
    printf("^");
}
void clear_bullet(int x,int y)
{
    gotoxy(x,y);
    printf(" ");
}
int random(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
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
void gen_star()
{
    for (int i = 0; i < 20; i++)
    {
        int x = random(10, 70);
        int y = random(2, 5);
        gotoxy(x, y);
        printf("*");
    }
}
int main()
{
    char ch='.';
    int x=38,y=20;
    int bx,by,i;
    int bullet = 0;
    setcursor(0);
    srand( time( NULL ) );
    gen_star();
    draw_ship(x,y);
    do
    {
        if (_kbhit())
        {
            ch=_getch();
            if(ch=='a')
            {
                draw_ship(--x,y);
            }
            if(ch=='s')
            {
                draw_ship(++x,y);
            }
            if(bullet!=1 && ch==' ')
            {
                bullet=1;
                bx=x+3;
                by=y-1;
            }
            fflush(stdin);
        }
        if (bullet==1)
        {
            clear_bullet(bx,by);
            if (by==2)
            {
                bullet=0;
            }
            else if (cursor(bx,by-1) == '*')
            {
                clear_bullet(bx, by - 1);
                bullet=0;
                Beep(700, 500);
            }
            else
            {
                draw_bullet(bx,--by);
            }
        }
        Sleep(100);
    }
    while (ch!='x');
    return 0;
}
