#include<stdio.h>
int main()
{
    int a[100];       //定义一个一维整数数组A，在一行中输入N个整数（换行符表示输入结束，N < 100）
                      //存入数组A，对数组A中的前M个元素做从小到大排序，数组其它元素保持不变。
    int i,n;
    for(i=0;i>=0;i++)
    {
        scanf("%d",&a[i]);
        if(getchar()=='\n')break;//输入数组
    }
    int j,point,t;
    n=i;
    scanf("%d",&point);//输入从哪一位开始截断
    for(j=1;j<point;j++)
      for(i=0;i<=point-1-j;i++)
        if(a[i]>a[i+1])
        {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }     
    for(i=0;i<=n;i++)
    printf("%d ",a[i]);
    return 0;
}