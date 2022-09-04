/*
65010262 ณภัทร ผาตินาวิน
Assignment 1
*/
#include<stdio.h>
#include<windows.h>
void draw_ship(int, int);

int main()
{
    int x, y;
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);
    draw_ship(x, y);
    return 0;
}
void draw_ship(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" <-0-> ");
}
