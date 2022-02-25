#include<stdio.h>
int main()
{
    int x,y,z,sum1,sum2;
    scanf("%d,%d,%d",&x,&y,&z);
    sum1=x*y+z;
    sum2=x*(y+z);
    printf("%d,%d",sum1,sum2);
    return 0;
}