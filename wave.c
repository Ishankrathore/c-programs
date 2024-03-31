#include<stdio.h>
int wavearray(int arr[],int n)
{   sort(arr,10);
for(int i=0;i<n-1;i=i+2)
{ 
    
    swap(&arr[i],&arr[i+1]);
}
for(int i=0;i<n;i++)
{
    printf("%d",arr[i]);
}

}
int sort(int arr[],int n)
{ 
    int i,j,t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            { t=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=t; }

        }
    }

}
int swap(int*p,int*q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;

}
int main()
{
    int arr[10]={10,5,6,3,2,20,100,80};
    wavearray(arr,10);
return 0;}