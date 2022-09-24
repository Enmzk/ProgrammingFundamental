#include<stdio.h>

int main()
{
    int sec;
    scanf("%d", &sec);
    printf("%d:%02d:%02d", (sec/3600), (sec%3600)/60, sec%60);
}
