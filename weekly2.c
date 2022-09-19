#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int sum_of_pow = 0, pow_of_sum = 0;
    printf("Enter number : ");
    scanf("%d", &n);
    while (n > 0)
    {
        sum_of_pow += pow(n,2);
        pow_of_sum += n;
        n--;
    }
    printf("%.0f", pow(pow_of_sum, 2) - sum_of_pow);
}
