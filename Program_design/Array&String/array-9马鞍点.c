#include<stdio.h>
int main()
{
    int m,n,min,max,l,j,i;
    int a[100][100],hang[100],lie[100];
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    { 
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(j==0)
             min=a[i][j],l=0;        
            if(j!=0&&a[i][j-1]>a[i][j]) 
             min=a[i][j],l=j; 
        }
        hang[i]=min;         //每一行最小的数储存在hang【i】中
        lie[i]=l;            //lie【i】中是每行最小数的列数
    }
    int pan=0,cun=0;
    for(i=0;i<m;i++)
    {
        max=hang[i];
        l=lie[i];            
        for(j=0;j<m;j++) 
        {
            if(max<a[j][l])
            max=a[j][l];
        }
        if(max==hang[i])            //判断是否为此列最大的数
        {
            printf("%d %d %d\n",i,lie[i],max);
            cun++;
        }
    }
    if(cun==0)
    printf("no\n");
    return 0;
}