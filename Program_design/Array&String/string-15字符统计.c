#include<string.h>
#include<stdio.h>
int main()
{
    char y,a[100];
    int n,i,pan,ji=0;
    scanf("%c %d",&y,&pan); //y为要计数的字母
    scanf("%s",a);
    n=strlen(a);
    if(pan==1)         //为1时区分大小写
    {
        for(i=0;i<n;i++)
        if(a[i]==y)
         ji=ji+1;
        printf("%d",ji);
    }
    if(pan==0)         //为0时不区分大小写
    {
        for(i=0;i<n;i++)
        if(a[i]==y||a[i]==y+32||a[i]==y-32)
         ji=ji+1;
        printf("%d",ji);
    }
    return 0;
}