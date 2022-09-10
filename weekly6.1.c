#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int upper = 0, lower = 0;
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 65) && (str[i] <= 90))
        {
            upper++;
        }
        else if ((str[i] >= 97) && (str[i] <= 122))
        {
            lower++;
        }
    }
    printf("Uppercase: %d\nLowercase: %d", upper, lower);
}
