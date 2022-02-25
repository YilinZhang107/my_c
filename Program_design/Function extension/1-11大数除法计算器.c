#include<stdio.h>
int main()
{
    int a,b,c,i,yu;
    scanf("%d %d %d",&a,&b,&c);  //输入被除数 除数 需要精确的位数
    printf("%d.",a/b);      //先输出个位
    for(i=0;i<c;i++)
    {
        yu=a%b;          //此处模拟人工计算
        a=yu*10;    //*10 重点！！！
        if(i!=c-1)    //不是最后一位时
        {
            if(yu==0)break;       //余数为0时停止
            else 
            printf("%d",a/b);     //否则输出一位
        }
        else         //最后一位 需要思考四舍五入
        {
            if(a%b>=5)          //五入
            printf("%d",a/b+1);
            else
            printf("%d",a/b);   //四舍 
        }
    }
    return 0;
}