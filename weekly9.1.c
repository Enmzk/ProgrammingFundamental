#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if ((n / 2) * 2 != n)
    {
        printf("Odd number");
    }
    else
    {
        printf("Even number");
    }
}
