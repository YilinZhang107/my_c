#include<stdio.h>
int main()
{
    int x,i,t;
    double sum=0,mu=1,zi=2;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        sum=sum+zi/mu;
        t=zi;
        zi=zi+mu;
        mu=t;
    }
    printf("%.2f",sum);
    return 0;

}