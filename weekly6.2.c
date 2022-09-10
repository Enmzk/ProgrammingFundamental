#include<stdio.h>
#include<string.h>

int main()
{
    char c = ' ';
    int upper = 0, lower = 0;
    while (c != '\n')
    {
        scanf("%c", &c);
        if ((c >= 65) && (c <= 90))
        {
            upper++;
        }
        else if ((c >= 97) && (c <= 122))
        {
            lower++;
        }
    }
    printf("Uppercase: %d\nLowercase: %d", upper, lower);
}
