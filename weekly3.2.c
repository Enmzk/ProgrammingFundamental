#include<stdio.h>
#include<math.h>
int main()
{
    float row, column;
    scanf("%f", &row);
    float mid = ceil(row / 2);
    int center = (int)mid;
    if ((int)row % 2 == 0)
    {
        column = row - 1;
    }
    else
    {
        column = row;
    }
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            if ((i <= center) && (j <= center))
            {
                if (i + j == center + 1)
                {
                    printf("*");
                }
                else
                {
                    printf("-");
                }
            }
            else if ((i <= center) && (j > center))
            {
                if (j == center + i - 1)
                {
                    printf("*");
                }
                else
                {
                    printf("-");
                }
            }
            else if ((i > center) && (j <= center))
            {
                if (((int)row % 2 == 0)&&(j == i - center))
                {
                    printf("*");
                }
                else if (((int)row % 2 == 1) && (j == i - center + 1))
                {
                    printf("*");
                }
                else
                {
                    printf("-");
                }
            }
            else
            {
                if (i + j == row + center)
                {
                    printf("*");
                }
                else
                {
                    printf("-");
                }
            }
        }
        printf("\n");
    }
}
