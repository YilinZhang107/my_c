#include<stdio.h>
#include<math.h>
int main()
{
    double x,y;                      //四个建筑均在坐标轴四个方向（2，2）处，所以使用绝对值   
    scanf("%lf %lf",&x,&y);          //（注意求根公式中的平方）
    x=fabs(fabs(x)-2),y=fabs(fabs(y)-2);
    if(sqrt(x*x+y*y)<=1)
    printf("10");
    else
    {
        printf("0");
    }
    return 0;
    
}