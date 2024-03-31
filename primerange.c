#include <stdio.h>
#include <math.h>
int prime(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a, b, i;
    printf("enter range");
    scanf("%d%d", &a, &b);
    printf("\nprime number between %d and %d:\n", a, b);
    for (i = a; i <= b; i++)
    {
        if(i==1)
        continue;
        if (prime(i) == 1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}