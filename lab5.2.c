/*
65010262 ณภัทร ผาตินาวิน
Assignment 2
*/
#include<stdio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship()
{
    printf(" <-0-> ");
}
int main()
{
    for (int i = 0; i < 80; i++)
    {
        gotoxy(i,20);
        draw_ship();
        Sleep(500);
    }
    return 0;
}
