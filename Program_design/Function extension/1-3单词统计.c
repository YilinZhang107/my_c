#include<stdio.h>
int main()
{
    char string[100];
    int i=0,n;//n：总字符串长度
    for(i=0;i<100;i++)             //输入一个字符串，第二行输入是需要统计的单词，
    {
        scanf("%c",&string[i]);       //输出此单词 后输出此单词出现的次数
        if(string[i]=='\n')break;
    }
    n=i;         
    char tong[8];
    for(i=0;i<8;i++)
    {
        scanf("%c",&tong[i]);
        if(tong[i]=='\n')break;
    }
    int l;       //l：需要统计的单词长度
    l=i;              
    int j,ci=0;                 //ci：出现的次数
    for(i=0,j=0;i<n;i++)
    {
        if(string[i]!=tong[j])
        {   
            j=0;
            continue;
        }
        else
        {
            j++;
            if((j==l&&string[i-l]==' '&&(string[i+1]==' '||string[i+1]=='\000'))||(j==l&&i-l==-1&&(string[i+1]==' '||string[i+1]=='\000')))
            {
                ci=ci+1;
                j=0;
            }
        }
    }
    for(i=0;i<l;i++)
     printf("%c",tong[i]);
    printf(" %d",ci);
    return 0;
}