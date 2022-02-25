#include<stdio.h>
int main()
{
    char a[500];
    int i,j,zong=0;
    for(i=0;i<500;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]==10)break;
        else if(a[i]<=122&&a[i]>96)
        a[i]=a[i]-32;
        else if(a[i]>=65&&a[i]<=90)
        a[i]=a[i]+32;
        else if(a[i]>=47&&a[i]<=57)
        zong++;
    }
    printf("%d\n",zong);
    for(j=0;j<=i;j++)
    printf("%c",a[j]);
    return 0;
}