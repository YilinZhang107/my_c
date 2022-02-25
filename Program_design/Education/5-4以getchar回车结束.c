#include<stdio.h>
int main()
{
    int n,a[101],j,i,t;
    for(i=0;i>=0;i++)
    {
        scanf("%d",&a[i]);
        if(getchar()=='\n')break;
    }    
    n=i+1;
    for(j=1;j<n;j++)
      for(i=0;i<=n-j;i++)
        if(a[i]>a[i+1])
        {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }    
    int sum=1;
    for(i=0;i<n;i++)
    {
       if(a[i]!=a[i+1])
       {
           printf("%d %d\n",a[i],sum);
           sum=1;
       }
       else
       sum++;
    }
    return 0;
}