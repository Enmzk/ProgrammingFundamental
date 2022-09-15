#include<stdio.h>

int main()
{
    int num;
    int convert[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char roman1[] = "MDCLXVI";
    char roman2[] = "CCXXII";
    scanf("%d", &num);
    while (num > 0)
    {
        for (int i = 0; i < 13; i++)
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
