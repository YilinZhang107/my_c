#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    int i,j;
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    int p=0,l;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        { 
            if(a[i][j]==a[i][j+1])//当此数和下一个数相同时，进入循环将后面相同数化为0
            {
                for(l=1;l<n-j;l++)//进入循环判断后面的数
                {
                 if(a[i][j]==a[i][j+l+1])//和第三个数相同
                 {
                    p++;//p用来判断是否够三个数
                    a[i][j+l+1]=0;
                    if(a[i][j+1+l]!=a[i][j])break;//！出现不同时及时跳出循环
                 }
                }
                if(p!=0)//！=0时表明有三个及以上相同数
                a[i][j+1]=0;
                 
            }
        }      
    }
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        printf("%d ",&a[i][j]);
    return 0;
}