#include<stdio.h>

int main()
{
    int m, n, num;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for (int i = 0; i < 2 * m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < m)
            {
                scanf("%d", &matrix[i][j]);
            }
            else
            {
                scanf("%d", &num);
                matrix[i-m][j] += num;
            }
        }
    }
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
