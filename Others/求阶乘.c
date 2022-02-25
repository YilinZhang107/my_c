#include<stdio.h>
int main()
{
    int n;
    int fact(int);
    printf("Input n:");
    scanf("%d",&n);
    printf("%d!=%d\n",n,fact(n));
}
int fact(int n)
{
   int pro;//
    if(n<=1)
    pro=1;
    else
    pro=n*fact(n-1);
    return(pro);
}