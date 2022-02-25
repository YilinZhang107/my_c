#include<stdio.h>
int main()
{
    int a[100];      //定义一维整数数组， 从键盘输入N ( N < 100)个整数，将数组元素逆序存储。
    int n,i;
    scanf("%d",&n);          //10
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);         //0 1 2 3 4 5 6 7 8 9
    }
    for(i=n-1;i>=0;i--)
    printf("%d ",a[i]);          //9 8 7 6 5 4 3 2 1 0
    return 0;
    

}