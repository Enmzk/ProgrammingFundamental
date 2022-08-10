#include<stdio.h>
int main()
{
    int n;
    int i = 2;
    printf("Enter number : ");
    scanf("%d", &n);
    printf("Factoring Result : ");
    while (n != 1)
    {
        if (n % i == 0)
        {
            n/=i;
            printf("%d", i);
            if (n != 1)
            {
                printf(" x ");
            }
        }
        else
        {
            i++;
        }
    }
}
