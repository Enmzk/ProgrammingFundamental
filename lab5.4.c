/*
65010262 ณภัทร ผาตินาวิน
Assignment 4
*/
#include<stdio.h>
#include<windows.h>
void draw_ship(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" <-0-> ");
}
void erase_ship (int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("      ");
}
int main()
{
    char ch=' ';
    int x=38,y=20;
    draw_ship(x,y);
    do
    {
        if (_kbhit())
        {
            ch=_getch();
            if(ch=='a')
            {
                if (x <= 0)
                {
                    x++;
                }
                draw_ship(--x,y);
            }
            if(ch=='w')
            {
                if (y <= 0)
                {
                    y++;
                }
                draw_ship(x,--y);
                erase_ship(x, y + 1);
            }
            if(ch=='d')
            {
                if (x >= 80)
                {
                    x--;
                }
                draw_ship(++x,y);
            }
            if(ch=='s')
            {
                if (y >= 20)
                {
                    y--;
                }
                draw_ship(x,++y);
                erase_ship(x, y - 1);
            }
            fflush(stdin);
        }
        Sleep(100);
    }
    while (ch!='x');
    return 0;
}
