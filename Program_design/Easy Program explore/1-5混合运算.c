#include<stdio.h>
int main()
{
    int n,i;
    int x,z=0;//输出日销售总额和平均每股成交价格
    double y,avarage=0,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %lf",&x,&y);
        sum=sum+x*y;
        z=z+x;
        avarage=avarage+y;
    }
    printf("%.2f %.2f",sum,sum/z);
    return 0;

}