#include<stdio.h>
int main()
{
    int temp = 0;
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                temp += j;
            }
        }
        if (temp == i)
        {
            printf("%d ", i);
        }
        temp = 0;
    }
}
