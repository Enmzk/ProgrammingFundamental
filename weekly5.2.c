#include<stdio.h>
int main()
{
    int height;
    scanf("%d", &height);
    int width = (height * 2) - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if ((j >= height - i) && (j <= height + i))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
