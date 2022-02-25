#include<stdio.h>
int main()
{
    struct fu
    {
        double shi;
        double xu;
    };
    int number;
    scanf("%d",&number);
    struct fu n[number];
    int i;
    double shiz=0,xuz=0;
    for(i=0;i<number;i++)
    {
        scanf("%lf %lf",&n[i].shi,&n[i].xu);
        shiz=shiz+n[i].shi;
        xuz=xuz+n[i].xu;
    }
    if(xuz!=0)
    printf("%.2lf%.2lfi",shiz,xuz);
    else
    printf("%.2lf",shiz);
    return 0;
}