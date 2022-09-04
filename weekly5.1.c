#include<stdio.h>
int main()
{
    int height;
    scanf("%d", &height);
    int width = (height * 2) - 1;
    int space = height - 1;
    for (int i = 1; i <= height; i++, space--)
    {
        for (int j = 1; j <= width; j++)
        {
            if ((j <= space) || (j > height + i - 1))
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}
