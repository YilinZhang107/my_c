#include<stdio.h>
int main()
{
    struct riqi
    {
        int nian;
        int yue;
        int ri;
        int tian;
    };
    struct riqi n;
    scanf("%d/%d/%d",&n.nian,&n.yue,&n.ri);
    if(n.nian%400==0||(n.nian%4==0&&n.nian%100!=0))
    {
        if(n.yue==1)n.tian=n.ri;
        if(n.yue==2)n.tian=n.ri+31;
        if(n.yue==3)n.tian=n.ri+60;
        if(n.yue==4)n.tian=n.ri+91;
        if(n.yue==5)n.tian=n.ri+121;
        if(n.yue==6)n.tian=n.ri+152;
        if(n.yue==7)n.tian=n.ri+182;
        if(n.yue==8)n.tian=n.ri+213;
        if(n.yue==9)n.tian=n.ri+244;
        if(n.yue==10)n.tian=n.ri+274;
        if(n.yue==11)n.tian=n.ri+305;
        if(n.yue==12)n.tian=n.ri+335;
    }
    else
    {
        if(n.yue==1)n.tian=n.ri;
        if(n.yue==2)n.tian=n.ri+31;
        if(n.yue==3)n.tian=n.ri+59;
        if(n.yue==4)n.tian=n.ri+90;
        if(n.yue==5)n.tian=n.ri+120;
        if(n.yue==6)n.tian=n.ri+151;
        if(n.yue==7)n.tian=n.ri+181;
        if(n.yue==8)n.tian=n.ri+212;
        if(n.yue==9)n.tian=n.ri+243;
        if(n.yue==10)n.tian=n.ri+273;
        if(n.yue==11)n.tian=n.ri+304;
        if(n.yue==12)n.tian=n.ri+334;
    }
    printf("%d\n%d\n%d\n%d",n.nian,n.yue,n.ri,n.tian);
    return 0;
}