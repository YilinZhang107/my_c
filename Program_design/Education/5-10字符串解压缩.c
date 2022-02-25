#include<stdio.h>
#include<string.h>
int main()
{
    char a[50],b[100];
    int i,n,j,t,l,ci=0;
    scanf("%s",a);
    n=strlen(a);           // 计算字符串长度函数
    for(i=0,j=0;i<n;i++)
    {
        if(a[i]>=49&&a[i]<=57)  // 判断是否为数字
        {
            if(a[i+1]>=49&&a[i+1]<=57)   // 是否为2位数
              {
                ci=(a[i]-48)*10+(a[i+1]-48);
                t=a[i-1];
                 for(l=0;l<ci-1;l++)
                   b[j+l]=t;     // 套入新数组中
                i++;
                j=j+ci-1;
              }
            else                    // 个位数情况
            {ci=a[i]-48;
            t=a[i-1];
            for(l=0;l<ci-1;l++)
              b[j+l]=t;
            j=j+ci-1;
            }
        }     
        else 
        {
            b[j]=a[i];
            j++;
        } 
    }
    for(i=0;i<j;i++)
        printf("%c",b[i]);
    return 0;
}