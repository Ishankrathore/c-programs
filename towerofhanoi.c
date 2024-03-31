#include<stdio.h>

void tower(int n,char a,char b,char c)
{
    if(n!=0)
    {
        tower(n-1,a,c,b);
        printf("%c -> %c\n",a,c);
        tower(n-1,b,a,c);    
    }   
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    tower(n,'A','B','C');
    return 0;
}


