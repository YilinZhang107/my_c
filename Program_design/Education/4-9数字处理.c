#include<stdio.h>
int main()
{
    int i,number=0;
    int a[100000];
    int chu(int x);
    for(i=0;i>=0;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)break;
    }
    number=i;
    for(i=0;i<number;i++)
    {
        printf("%d\n",chu(a[i]));
    }
    return 0;
}
int chu(int x)
{
    int sum=0,y,i;
    for(i=0;i>=0;i++)
    {
        sum=sum+x%10;
        x=x/10;
        if(x==0)break;
    }
    if(sum>9)
    y=chu(sum);
    else
    y=sum;
    return (y);

}