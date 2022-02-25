#include<stdio.h>
int main()
{
    int h;
    char m1,m2;
    scanf("%d:%c%c",&h,&m1,&m2);
    if(h<12)
    printf("%d:%c%c AM",h,m1,m2);
    else if(h=12)
    printf("%d:%c%c PM",h,m1,m2);
    else
    printf("%d:%c%c PM",h-12,m1,m2);
    return 0;

}