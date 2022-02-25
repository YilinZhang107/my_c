#include<string.h>
#include<stdio.h>
int main()
{
    char a[50];
    int i,n=0,l,j;
    for(i=0;i<3;i++)      //输入三行字符串，统计单词个数
    {
        fgets(a,50,stdin);//此处gets和fgets都可
        l=strlen(a);
        for(j=0;j<l;j++)
         if(a[j]==' ')
          n++;
        n++;  
    }      
    printf("%d",n);
    return 0;
}