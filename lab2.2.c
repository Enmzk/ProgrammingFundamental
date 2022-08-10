#include<stdio.h>
int main()
{
    int num1, num2, temp, gcd = 1;
    printf("Enter first number : ");
    scanf("%d", &num1);
    printf("Enter second number : ");
    scanf("%d", &num2);
    if (num2 > num1)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    for (int i = num2; i >= 1; i--)
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            gcd = i;
            break;
        }
    }
    printf("Greatest common divisor = %d", gcd);
}
