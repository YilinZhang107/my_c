#include<stdio.h>
int main()
{
    int pan=0,n,i;              //输入一个数，输出此数之前的所有水仙花数
    int shuixian(int x);
    scanf("%d",&n);
    for(i=100;i<=n;i++)
    {
        if(shuixian(i)==1)
        {
            printf("%d ",i);
            pan=1;
        }
    }
    if(pan==0)
    printf("no");
    return 0;
}
int shuixian(int x)
{
    int i,pan,bai,shi,ge;
    bai=x/100;
    shi=x/10%10;
    ge=x%10;
    if(bai*bai*bai+shi*shi*shi+ge*ge*ge==x)
    pan=1;
    else
    pan=0;
    return (pan);
}