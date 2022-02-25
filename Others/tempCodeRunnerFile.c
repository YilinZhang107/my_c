#include<stdio.h>
int main()
{
    struct ji
    {
        int shu;//数字
        int number;//此数字出现的个数
    };
    int n,t,j,i,l,pan=0,pan1=0;
    scanf("%d",&n);//输入总共有多少个数
    struct ji zu[n];//建立结构体数组
    for(i=0;i<n;i++)//数组初始化
    {
        zu[i].shu=-1;
        zu[i].number=1; 
    }
    for(i=0,l=0;i<n;i++,l++)//开始输入n个数  i为循环 l为不重复的数个数
    {
        scanf("%d",&t);
        for(j=0;j<l;j++)
        {
            if(t==zu[j].shu)      //已有此数则此数的次数+1
            {
                zu[j].number++;
                pan=1;
                l--;
                pan1=1;
                break;
            }
        }
        if(pan==0)zu[l].shu=t;
        pan=0;
    }
    if(pan1==1)l=l+1;       //此时l为有效数组长度
    for(i=0;i<l;i++) //冒泡排序
    {
        for(j=0;j<l-i-1;j++)
         if(zu[j].number<zu[j+1].number)
         {
           t=zu[j].number;
           zu[j].number=zu[j+1].number;
           zu[j+1].number=t;
           t=zu[j].shu;
           zu[j].shu=zu[j+1].shu;
           zu[j+1].shu=t;
         }
         if(zu[j].number==zu[j+1].number) //题目要求当个数相同时，小数在上
           if(zu[j].shu>zu[j+1].shu&&zu[j+1].shu!=-1)
            {
                t=zu[j].shu;
                zu[j].shu=zu[j+1].shu;
                zu[j+1].shu=t;
            }
    }
    for(i=0;i<l;i++) //输出
    {
        if(zu[i].shu!=-1)
        printf("%d %d\n",zu[i].shu,zu[i].number);
        else //有点多余
        break;
    }
    return 0;
}