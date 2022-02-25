#include<stdio.h>
int main()
{
    int a[10][100],cha,zu,j,i,t,l;
    scanf("%d",&zu);                 //请写一个程序，判断给定整数序列能否构成一个等差数列。
    for(i=0;i<zu;i++)
    {                             //第一行为整数T（T<=10），代表测试数据的数目。每组数据由两
                                  //行构成，第一行只有一个整数n（<100），表示序列长度（该序列
                                  //中整数的个数），第二行为n个整数，
        scanf("%d",&a[i][0]);
        for(j=1;j<=a[i][0];j++)
        scanf("%d",&a[i][j]);     //对每一组数据输出判断结果，不能构成等差数列输出“no”，能构
                        //成等差数列输出表示公差（相邻两项的差）绝对值的一个整数，输出后换行。  
    }
    for(l=0;l<zu;l++)
     for(j=1;j<a[l][0];j++)
      for(i=1;i<=a[l][0]-j;i++)
        if(a[l][i]>a[l][i+1])
        {
            t=a[l][i];
            a[l][i]=a[l][i+1];
            a[l][i+1]=t;
        }     
    for(i=0;i<zu;i++)
    {
        cha=a[i][2]-a[i][1];
        for(j=2;j<a[i][0];j++)
          if(a[i][j+1]-a[i][j]!=cha)break;    
        if(j==a[i][0])
        printf("%d\n",cha);
        else
        printf("no\n");
    }
    return 0;
    
}