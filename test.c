#include<stdio.h>
#include<windows.h>
#include<time.h>
int main()
{
int i;
srand( time( NULL ) );
for (i=0;i<10;i++)
{
    Beep(700 + (i * 100), 500);
    printf("%d\n", 700 + (i * 100));
}
return 0;
}
