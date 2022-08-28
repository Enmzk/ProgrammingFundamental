#include<stdio.h>
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
        scanf("%[^\n]s", chain[k]);
    }
    printf("%s", chain[1]);

}
