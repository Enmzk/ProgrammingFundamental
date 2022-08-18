#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int wide = (4*n)-3;
    for (int i = 1; i <= (2*n)-1; i++)
    {
        for (int j = 1; j <= wide; j++)
        {
            if (i <= n)
            {
                if ((j == 1) || (j == wide))
                {
                    printf("*");
                }
                else if ((j % 2 == 1) && ((j < (2*i)) || (j > wide-(2*i))))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if ((j == 1) || (j == wide))
                {
                    printf("*");
                }
                else if ((j % 2 == 1) && ((j < (4*n)-(2*i)) || (j > wide-(4*n)+(2*i))))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
