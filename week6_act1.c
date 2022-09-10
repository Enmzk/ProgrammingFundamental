/*
65010262 ณภัทร ผาตินาวิน
*/
#include<stdio.h>
int main()
{
    char s[100];
    char *p;
    p = s;
    scanf("%s", s);
    while (*p != '\0')
    {
        if ((*p >= 97) && (*p <= 122))
        {
            printf("%c", *p - 32);
        }
        else if ((*p >= 65) && (*p <= 90))
        {
            printf("%c", *p + 32);
        }
        p++;
    }
}
