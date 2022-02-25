#include<stdio.h>
int main()
{
    int end,x,y,z;
    int suan(int x,int y,char c);
    scanf("%d%c",&x,&z);
    y=x%10;
    x=x/10;
    if(y!=0)
    {
      end=suan(x,y,z);
      printf("%d%c%d=%d",x,z,y,end);
    }
    return 0;
}
int suan(int x,int y,char c)
{
    int he;
    switch(c)
    {
      case '+': he;break;
      case '-': he=x-y;break;
      case '*': he=x*y;break;
      case '/': he=x/y;break;
      case '%': he=x%y;break;
    }
    return (he);
}