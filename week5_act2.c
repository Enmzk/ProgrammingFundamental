#include<stdio.h>
int isPrime(int);
int main()
{
    int x;
    scanf("%d", &x);
    if (isPrime(x) == 1)
    {
        printf("Prime Number");
    }
    else
    {
        printf("Not Prime Number");
    }
    return 0;
}
int isPrime(int x)
{
    int check = 2;
    for(int i = 2; i <= x; i++)
    {
        if (x % i == 0)
        {
            check = i;
            break;
        }
    }
    if (check == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
