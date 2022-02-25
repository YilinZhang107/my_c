#include<stdio.h>
int main()
{
    long x,i,sum=0,now;
    printf("please get the n:");
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        now=now*10+2;
        sum=sum+now;
    } 
    printf("%d",sum);
    return 0;
}