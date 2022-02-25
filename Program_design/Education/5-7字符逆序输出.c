#include<stdio.h>
int main()
{
    char a[100];
    int number,i;
    for(i=0;i<100;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]==10)break;
    }
    number=i;
    for(i=number;i>=0;i--)
    printf("%c",a[i]);
    return 0;


}