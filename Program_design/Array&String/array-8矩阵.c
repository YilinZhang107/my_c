#include<stdio.h>
int main()
{
    int a[20][20];              //请写一个程序，对于一个m行m列（2＜m＜20）的方阵，求其每一行、
    int n,i,j,sum=0;            //每一列及主、辅对角线元素之和（注：主对角线是方阵从左上角到
    scanf("%d",&n);             //右下角的一条斜线，辅对角线是方阵从右上角到左下角的一条斜线）
    for(i=0;i<n;i++)            //，然后按照从大到小的顺序依次输出这些值。
     for(j=0;j<n;j++)
      scanf("%d",&a[i][j]);
    int b[50];                  //4
    for(i=0;i<n;i++)            //15 8 -2 6
      sum=sum+a[i][i];          //31 24 18 71
    b[0]=sum;                   //-3 -9 27 13
    sum=0;                      //17 21 38 69
    for(i=0,j=n-1;i<n;i++,j--)
      sum=sum+a[i][j];
    b[1]=sum;
    sum=0;
    for(i=0;i<n;i++)
      {
       for(j=0;j<n;j++)
       sum=sum+a[i][j];
       b[2+i]=sum;
       sum=0;
      }
    for(j=0;j<n;j++)
      {
       for(i=0;i<n;i++)
       sum=sum+a[i][j];
       b[2+n+j]=sum;
       sum=0;
      }
    int t;
    for(j=0;j<2*n+1;j++)
       for(i=0;i<2*n+1-j;i++)
         if(b[i]<b[i+1])
         {
           t=b[i];
           b[i]=b[i+1];
           b[i+1]=t;
         }  
    for(i=0;i<2*n+2;i++)
    printf("%d ",b[i]);  
    return 0;
}                            
                               
                           



 
    