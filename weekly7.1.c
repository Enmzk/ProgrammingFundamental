#include<stdio.h>

int main()
{
    int num;
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
        if (num >= 1000000)
        {
            printf("M");
            num-=1000000;
        }
        else if (num >= 900000)
        {
            printf("CM");
            num-=900000;
        }
        else if (num >= 500000)
        {
            printf("D");
            num-=500000;
        }
        else if (num >= 400000)
        {
            printf("CD");
            num-=400000;
        }
        else if (num >= 100000)
        {
            printf("C");
            num-=100000;
        }
        else if (num >= 90000)
        {
            printf("XC");
            num-=90000;
        }
        else if (num >= 50000)
        {
            printf("L");
            num-=50000;
        }
        else if (num >= 40000)
        {
            printf("XL");
            num-=40000;
        }
        else if (num >= 10000)
        {
            printf("X");
            num-=10000;
        }
        else if (num >= 9000)
        {
            printf("IX");
            num-=9000;
        }
        else if (num >= 5000)
        {
            printf("V");
            num-=5000;
        }
        else if (num >= 4000)
        {
            printf("IV");
            num-=4000;
        }
        else if (num >= 1000)
        {
            printf("M");
            num-=1000;
        }
        else if (num >= 900)
        {
            printf("CM");
            num-=900;
        }
        else if (num >= 500)
        {
            printf("D");
            num-=500;
        }
        else if (num >= 400)
        {
            printf("CD");
            num-=400;
        }
        else if (num >= 100)
        {
            printf("C");
            num-=100;
        }
        else if (num >= 90)
        {
            printf("XC");
            num-=90;
        }
        else if (num >= 50)
        {
            printf("L");
            num-=50;
        }
        else if (num >= 40)
        {
            printf("XL");
            num-=40;
        }
        else if (num >= 10)
        {
            printf("X");
            num-=10;
        }
        else if (num == 9)
        {
            printf("IX");
            num-=9;
        }
        else if (num >= 5)
        {
            printf("V");
            num-=5;
        }
        else if (num == 4)
        {
            printf("IV");
            num-=4;
        }
        else if (num >= 1)
        {
            printf("I");
            num-=1;
        }
    }
}
