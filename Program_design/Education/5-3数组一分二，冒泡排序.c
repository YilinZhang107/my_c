#include<stdio.h>
int main()
{
    int i,n,number,now,a[100],b[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    number=i-1;
    int n1=0,j;
    for(i=0;i<=number;i++)
    {
        if(a[i]%2!=0)
        {
            b[n1]=a[i];
            for(j=i;j<number;j++)
            a[j]=a[j+1];
            i=i-1;
            n1++;
            number--;
        }
    }
    n1=n1-1;
    int t;
    for(i=1;i<=number;i++)
    {
        for(j=0;j<=number-i;j++)
        if(a[j]<a[j+1])
        {
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;  
        }
    }
    for(i=1;i<=n1;i++)
    {
        for(j=0;j<=n1-i;j++)
        if(b[j]<b[j+1])
        {
            t=b[j+1];
            b[j+1]=b[j];
            b[j]=t;
        }
    }
    for(i=0;i<=number;i++)
    printf("%d ",a[i]);
    for(i=0;i<=n1;i++)
    printf("%d ",b[i]);
    return 0;

}