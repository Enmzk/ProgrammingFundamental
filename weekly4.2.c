#include<stdio.h>
#include<string.h>
int main()
{
    int len,n;
    int count = 0;
    scanf("%d", &len);
    scanf("%d", &n);
    char word1[len], word2[len];
    char chain[n][len];
    char broken[len];
    for (int k = 0; k < n; k++)
    {
        scanf("%s", chain[k]);
    }
    strcpy(broken, chain[n - 1]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (chain[i][j] != chain[i+1][j])
            {
                count++;
            }
        }
        if (count > 2)
        {
            strncpy(broken, chain[i], len);
            break;
        }
        count = 0;
    }
    printf("%s", broken);
}
