#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int sum_of_pow = 0, pow_of_sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum_of_pow += pow(i,2);
        pow_of_sum += i;
    }
    printf("%.0f", pow(pow_of_sum, 2) - sum_of_pow);
}
