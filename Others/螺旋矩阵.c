#include<stdio.h>
int main()
{
    int i=0,j=0,xun,m;
    scanf("%d",&m);
    int a[m][m],n=1;
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
         a[i][j]=0;             //先全部化为0
    i=0;j=0;
    for(xun=1;xun<=m*m;xun++)   //此循环次数不确定所以尽可能的设大
    {
        for(;j<m;j++)            //第一行开始，向右移动
        {
            a[i][j]=n;
            n++;
            if(a[i][j+1]!=0){j++;break;} //
        }
        j--;                 //经过循环后会j++所以减去一个j
        i++;                 //下个循环会直接向位置上填下一个数字，所以i++
        if(n==m*m+1)break;    //如果结尾是最后一个数停止
        for(;i<m;i++)              //后面的循环同理
        {
            a[i][j]=n;
            n++;
            if(a[i+1][j]!=0){i++;break;}
        }
        i--;
        j--;
        if(n==m*m+1)break;
        for(;j>=0;j--)
        {
            a[i][j]=n;
            n++;
            if(a[i][j-1]!=0){j--;break;}
        }
        j++;
        i--;
        if(n==m*m+1)break;
        for(;i>=0;i--)
        {
            a[i][j]=n;
            n++;
            if(a[i-1][j]!=0){i--;break;}
        }
        i++;
        j++;
        if(n==m*m+1)break;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
         printf("%d ",a[i][j]);
        printf("\n");
    } 
    return 0;
}