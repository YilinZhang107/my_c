#include<stdio.h>
int main()
{
    int x,y,number;
    int function(int x,int y);
    scanf("%d %d",&x,&y);
    number=function(x,y);
    printf("%d",number);
    return 0;
}
int function(int x,int y)
{
    int max,i,i1,wei=0,j,now,sum,l,number=0;
    int a[10];
    if(x>y)
    i=y,max=x;
    else
    i=x,max=y;
    for(;i<=max;i++)
    {
        if(i<100)continue;
        i1=i;
        wei=0;
		for(j=0;j>=0;j++)
        {
            if(i1==0)break;
            wei=wei+1;
            a[j]=i1%10;
            i1=i1/10;  
        }
        for(j=0;j<wei;j++)
        {
            now=1;
            for(l=1;l<=wei;l++)
            now=now*a[j];
            sum=sum+now;
        }
        if(sum==i)
        number=number+1;
        sum=0;
    }
    return (number);
}