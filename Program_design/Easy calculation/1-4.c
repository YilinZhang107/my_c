#include<stdio.h>
int main()
{
    int x,sum;
    char y;
    scanf("%d,%c",&x,&y);
    if(0<=x&&x<=4&&48<=y&&y<=53)
    printf("%d,%c",x+y,x+y);
    return 0;
    
}