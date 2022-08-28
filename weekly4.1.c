#include<stdio.h>
#include<string.h>
int main()
{
    int len,n;
    int count = 0;
    scanf("%d", &len);
    scanf("%d", &n);
    char word1[len], word2[len];
    char broken[len];
    broken[0] = 'x';
    scanf("%s", &word1);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%s", word2);
        for (int j = 0; j < len; j++)
        {
            if (word1[j] != word2[j])
            {
                count++;
            }
        }
        if (count > 2)
        {
            if (broken[0] == 'x')
            {
                strcpy(broken, word1);
            }
        }
        strcpy(word1, word2);
        count = 0;
    }
    if (n == 1)
    {
        printf("%s", word1);
    }
    else if (broken[0] == 'x')
    {
        printf("%s", word2);
    }
    else
    {
        printf("%s", broken);
    }
}
