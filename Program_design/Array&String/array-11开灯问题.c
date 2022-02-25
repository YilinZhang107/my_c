#include<stdio.h>
int main()
{
    int n,m,i,j;//一间教室里有n盏灯，编号从1-n，开始时全部是关闭状态，现在有m个人进入教室，
    scanf("%d %d",&n,&m);//第1个人把所有灯打开，第2个人只按下所有编号为2的倍数的开关
    int deng[n+1];
    for(i=0;i<=n;i++)          //输出最后开着的灯的序号
     deng[i]=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            if(j%i==0)
            {
                if(deng[j]==0)
                deng[j]=1;
                else
                deng[j]=0;
            }
    }
    for(i=1;i<=n;i++)
    {
        if(deng[i]==1)
        printf("%d ",i);
    }
    return 0;
}