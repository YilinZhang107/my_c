#include<stdio.h>
int main()
{
    void swap(int *x,int max,int min);
    int max(int a[20],int n);
    int min(int a[20],int n);
    int i,a[20];                     //将数列中的最大值和最小值交换再输出
    int n,mi,ma;
    scanf("%d",&n);  //输入数列有几个数
    for(i=0;i<n;i++)
      scanf("%d",&a[i]); //输入数列
    ma=max(a,n);
    mi=min(a,n);
    int *pa=a;
    swap(pa,ma,mi);   //交换最值
    for(i=0;i<n;i++)
      printf("%d ",a[i]);
    return 0;  
}

int max(int a[20],int n)    //算出最大的数是第几位
{
    int max=0,i;
    for(i=1;i<n;i++)
      if(a[i-1]<a[i])
      max=i;
    return (max);
}

int min(int a[20],int n)  //最小数为第几位
{
    int min=0,i;
    for(i=1;i<n;i++)
      if(a[i-1]>a[i])
      min=i;
    return (min);
}

void swap(int *x,int max,int min)    //用指针交换最大位和最小位
{
    int t;
    t=*(x+max);
    *(x+max)=*(x+min);
    *(x+min)=t;
}