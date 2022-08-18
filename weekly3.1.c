#include<stdio.h>
#include<math.h>
int main()
{
    float row, column;
    scanf("%f", &row);
    float kleft = ceil(row / 2);
    float kright = kleft;
    float mid = kleft;
    if ((int)row % 2 == 0)
    {
        column = row - 1;
    }
    else
    {
        column = row;
    }
    for (int i = 1; i <= row; i++, kleft--, kright++)
    {
        for (int j = 1; j <= column; j++)
        {
            if ((j == kleft) || (j == kright))
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
        if (i >= mid)
        {
            if ((int)row % 2 == 1)
            {
                kleft+=2;
                kright-=2;
            }
            else
            {
                if (i == mid)
                {
                    kleft+=1;
                    kright-=1;
                }
                else
                {
                    kleft+=2;
                    kright-=2;
                }
            }
        }
    }
}
