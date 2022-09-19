#include<stdio.h>

int main()
{
    int num;
    int convert[] = {1000000, 900000, 500000, 400000, 100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char roman1[] = "MDCLXVMDCLXVI";
    char roman2[] = "CCXXIICCXXII";
    scanf("%d", &num);
    int num_check = num;
    while (num_check > 4000)
    {
        if (num_check >= 1000000)
        {
            printf("-");
            num_check-=1000000;
        }
        else if (num_check >= 900000)
        {
            printf("-");
            num_check-=900000;
        }
        else if (num_check >= 500000)
        {
            printf("-");
            num_check-=500000;
        }
        else if (num_check >= 400000)
        {
            printf("-");
            num_check-=400000;
        }
        else if (num_check >= 100000)
        {
            printf("-");
            num_check-=100000;
        }
        else if (num_check >= 90000)
        {
            printf("-");
            num_check-=90000;
        }
        else if (num_check >= 50000)
        {
            printf("-");
            num_check-=50000;
        }
        else if (num_check >= 40000)
        {
            printf("-");
            num_check-=40000;
        }
        else if (num_check >= 10000)
        {
            printf("-");
            num_check-=10000;
        }
        else if (num_check >= 9000)
        {
            printf("-");
            num_check-=9000;
        }
        else if (num_check >= 5000)
        {
            printf("-");
            num_check-=5000;
        }
        else if (num_check >= 4000)
        {
            printf("-");
            num_check-=4000;
        }
    }
    printf("\n");
    while (num > 0)
    {
        for (int i = 0; i < 25; i++)
        {
            if (num >= convert[i])
            {
                if (i % 2 == 0)
                {
                    printf("%c", roman1[i/2]);
                }
                else
                {
                    printf("%c", roman2[i/2]);
                    printf("%c", roman1[i/2]);
                }
                num-=convert[i];
                i--;
            }
        }
    }
}
