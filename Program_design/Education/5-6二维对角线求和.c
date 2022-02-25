#include<stdio.h>
int main()
{
    int a[20][20];
    int n,i,j,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
      scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
      sum=sum+a[i][i];
    for(i=0,j=n-1;i<n;i++,j--)
      sum=sum+a[i][j];
    if(n%2==1&&n>1)
      sum=sum-a[(n-1)/2][(n-1)/2];
    printf("%d",sum);  
    return 0;
}