#include<string.h>
#include<stdio.h>
int main()
{
    char c[100];
    int n,i;
    fgets(c,100,stdin);            //即第1个字母变成第26个字母，第i个字母变成第（26-i+1）
    n=strlen(c);                    //个字母……非字母字符不变。要求编程将密码译回原文。
    for(i=0;i<n-1;i++)
    {
        if(c[i]>=97&&c[i]<=122)
        c[i]=122-(c[i]-96)+1;
        else if(c[i]>=65&&c[i]<=90)
        c[i]=90-(c[i]-64)+1;
    }
    printf("%s",c);
    return 0;
}