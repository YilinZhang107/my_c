#include<stdio.h>
int main()
{
    char str[50];
    int i,d;
    for(i=0;i>=0;i++)
    {
        scanf("%c",&str[i]);         //输入一串字符
        if(str[i]=='\n')break;
        if(str[i-1]==' '&&str[i]==' ')break;
    }
    char *pstr;
    pstr=str;
    int n=i;
    scanf("%d",&d);                  //在d位处截断数组
    for(i=1;i<n-d;i++)
     printf("%c",*(pstr+d+i));       //输出后面的字符
    
    return 0;

}
