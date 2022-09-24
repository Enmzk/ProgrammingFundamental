#include<stdio.h>

int main()
{
    int sec;
    int hour = 0, minute = 0;
    scanf("%d", &sec);
    while (sec/60 > 0)
    {
        if (sec >= 3600)
        {
            sec-=3600;
            hour++;
        }
        else
        {
            sec-=60;
            minute++;
        }
    }
    printf("%d:%02d:%02d", hour, minute, sec);
}
