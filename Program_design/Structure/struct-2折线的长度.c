#include<stdio.h>
#include<math.h>
int main()
{
    struct zuobiao
    {
        float x;
        float y;
    };
    int i,n;
    scanf("%d",&n);
    struct zuobiao wei[n];
    for(i=0;i<n;i++)
     scanf("%f %f",&wei[i].x,&wei[i].y);
    float zong=0;
    for(i=1;i<n;i++)
    {
        zong=zong+sqrt((wei[i].x-wei[i-1].x)*(wei[i].x-wei[i-1].x)+(wei[i].y-wei[i-1].y)*(wei[i].y-wei[i-1].y));
    }
    printf("%.2f",zong);
    return 0;
}