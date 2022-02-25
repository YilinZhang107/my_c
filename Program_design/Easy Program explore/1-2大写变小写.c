#include<stdio.h>
int main()
{
    char a[10];
    int i;
    for(i=0;i<9;i++)
     scanf("%c",&a[i]);
    i=0;
    for(i=0;i<9;i=i+2)
     printf("%c",a[i]+32);
    printf("!");
    return 0;
}