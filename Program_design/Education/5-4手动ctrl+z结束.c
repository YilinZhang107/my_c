#include<stdio.h>
int main()
{
    int n=0,a[101],j,i,t;
    for(i=0;scanf("%d",&a[i])==1;i++)
    {
        n++;
    }
    for(j=1;j<n-1;j++)
      for(i=0;i<=n-j-1;i++)
        if(a[i]>a[i+1])
        {
            t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }    
    int sum=1;
    int m=a[0];
    for(i=1;i<n;i++)
    {
       if(a[i]==m)
       sum++;
       else
       {
           printf("%d %d\n",m,sum);
           m=a[i];
           sum=1;
       }
    }
    printf("%d %d\n",m,sum);
    return 0;
}