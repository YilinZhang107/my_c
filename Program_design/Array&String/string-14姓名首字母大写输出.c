#include<stdio.h>
int main()
{
    char a[20];
    int i;
    fgets(a,20,stdin);
    a[0]=a[0]-32;
    for(i=0;i<20;i++)
    {
        if(a[i-1]==' ')
        a[i]=a[i]-32;
    }
    printf("%s",a);
    return 0;
}