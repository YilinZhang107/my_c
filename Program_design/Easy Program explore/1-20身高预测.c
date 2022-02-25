#include<stdio.h>
int main()
{
    char sex,ti,chi;
    double fa,mo,gao;
    scanf("%c %lf %lf %c %c",&sex,&fa,&mo,&ti,&chi);
    if(sex==77)
    {
        gao=(fa+mo)*0.54;
        if(ti==89)
        gao=gao*1.02;
        if(chi==89)
        gao=gao*1.015;
    }
    else
    {
        gao=(fa*0.923+mo)/2;
        if(ti==89)
        gao=gao*1.02;
        if(chi==89)
        gao=gao*1.015;
    }
    printf("%.1fcm",gao);
    return 0;
}