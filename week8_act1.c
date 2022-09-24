#include<stdio.h>

int main()
{
    int level, score;
    char name[50];
    FILE* fp;
    fp = fopen("mytestfile.txt", "w");
    for (int i = 1; i <= 5; i++)
    {
        printf("Player%d profile\n", i);
        printf("Name: ");
        scanf("%s", name);
        printf("Level: ");
        scanf("%d", &level);
        printf("Score: ");
        scanf("%d", &score);
        fprintf(fp, "Name:%s\t Level:%d\t Score:%d\n", name, level, score);
    }
    fclose(fp);
}
