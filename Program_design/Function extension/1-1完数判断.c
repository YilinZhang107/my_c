#include<stdio.h>
int main()
{
    int a[50];                 //用函数判断是否为完数，输出此数字与1之间的所有完数
    int wanshu(int x) ;
    int n,i,j=0,pan;
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        pan=wanshu(i);
        if(pan==1)
        {
            a[j]=i;
            j++;
        }
    }
    for(i=0;i<j;i++)
    printf("%d ",a[i]);
    return 0;

}
int wanshu(int x)           //完数判断函数，是1否0
{                            //除自身外的所有公约数相加等于自身叫做完数
    int i,j=0,pan;
    for(i=1;i<x;i++)
    {
        if(x%i==0)
         j=j+i;
    }
    if(j==x)
    pan=1;
    else
    pan=0;
    return (pan);
}