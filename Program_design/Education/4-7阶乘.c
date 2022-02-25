#include<stdio.h>
int main()
{
    int m,n,a,b,c;
    double sum;
    double fac(int x);
    scanf("%d %d",&m,&n);
    a=fac(m);
    b=fac(n);
    c=fac(m-n);
    sum=a/b/c;
    printf("%.2f",sum);
    return 0;
}
double fac(int x)
{
    double f;
    if(x==1||x==0)
    f=1;
    else
    f=fac(x-1)*x;
    return (f);
}

