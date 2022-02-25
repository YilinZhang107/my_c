#include<stdio.h>
int main()
{
    int a[100],b[7]={0,0,0,0,0,0,101};
    int n,i,sum=0;
    double avarage;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     scanf("%d",&a[i]);
     if(a[i]>=90&&a[i]<=100)
      b[0]++;
     else if(a[i]>=80&&a[i]<90)
      b[1]++;
     else if(a[i]>=70&&a[i]<80)
      b[2]++;
     else if(a[i]>=60&&a[i]<70)
      b[3]++;
     else if(a[i]<60)
      b[4]++;
     if(a[i]>b[5])
      b[5]=a[i];
     if(a[i]<b[6])
      b[6]=a[i];
     sum=sum+a[i];
    }
    avarage=(double)sum/n;
    for(i=0;i<5;i++)
     printf("%d\n",b[i]);
    printf("%.1f\n",avarage);
    printf("%d-%d",b[6],b[5]);
    return 0;
}