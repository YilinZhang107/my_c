#include<stdio.h>
int main()
{
    int a[9],i;
    for(i=0;i<9;i++)
    scanf("%c",&a[i]);
    for(i=0;i<9;i=i+2)
    printf("%c",a[i]+32);
    printf("!");
    return 0;

}