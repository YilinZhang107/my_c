#include<stdio.h>
int main()
{
    double PI=3.1415926,a,b;
    int x,y;
    scanf("%d %d",&x,&y);
    x=x/20;
    y=y/20;
    a=4*PI*x*x*x/3*7.86;
    b=4*PI*y*y*y/3*19.3;
    printf("%.3f %.3f",a,b);
    return 0;

}