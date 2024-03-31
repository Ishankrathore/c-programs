#include <stdio.h>
void prime(int);
void perfect(int);
void evenorodd(int);
int main()
{
    int n, ch;
    printf("enter the number");
    scanf("%d", &n);
    printf("enter the choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        prime(n);break;
    case 2:
        perfect(n);break;
    case 3:
        evenorodd(n);
    }
}
void prime(int n)
{
    int c = 0,i;
    for ( i = 2; i < n; i++)
    {
        if (n % i == 0)
            c++;
    }
    if (c == 2)
        printf("number is prime");
    
    else printf("not");
}

void perfect(int n)
{
    int s = 0, r = 0,i;
    int num = n;
    for ( i = 1; i <= n; i++)
    {
        r = num % 10;
        s = s + r;
        num = num / 10;
    }
    if (s == n)
       { printf("perfect");
    }
    else printf("not");
}
void evenorodd(int n)
{
    if (n % 2 == 0)
       { printf("even");
    }
    else printf("odd");
}

