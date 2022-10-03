#include<stdio.h>

int main()
{
    int n;
    int odd[5] = {1, 3, 5, 7, 9};
    int check = 0;
    scanf("%d", &n);
    for (int i = 0; i < 5; i++)
    {
        if (n - (n/10) * 10 == odd[i])
        {
            check = 1;
            break;
        }
    }
    if (check == 1)
    {
        printf("Odd number");
    }
    else
    {
        printf("Even number");
    }
}
