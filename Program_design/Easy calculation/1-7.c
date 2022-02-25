#include<stdio.h>
int main()
{
    int a,b,sum;
    char c;
    scanf("%d,%d,%c",&a,&b,&c);
    
    sum=a/b;

    printf("%d,%d,%d",sum,a%b%c,a/b%c);
    return 0;
}