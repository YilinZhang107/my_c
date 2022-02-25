#include<stdio.h>
int main()
{
    int a[1000];
    int i,n,score=0;
    for(i=0;i>=0;i++)           //积分规则：连续为2时加2，4，6.....以此类推
    {
        scanf("%d",&a[i]);
        if(a[i]==0)break;
    }
    n=i;
    int bei=1;
    for(i=0;i<n+1;i++)
    {
        if(a[i-1]==2&&i>0&&a[i]==2)
        {
            score=score+2*bei;     //直接给分数加倍数，不改变本来分数，不影响判断
            bei=bei+1;
        }
        else
        bei=1;
        score=score+a[i];
    }
    printf("%d",score);
    return 0;
}