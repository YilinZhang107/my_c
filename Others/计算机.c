#include<stdio.h>
int main()
{
    int he,x,y;
    char z;
    scanf("%d%c",&x,&z);
    y=x%10;
    x=x/10;
    switch(z)
    {
      case '+': he=x+y;break;
      case '-': he=x-y;break;
      case '*': he=x*y;break;
      case '/': he=x/y;break;
      case '%': he=x%y;break;
    }
    printf("%d",he);
    return 0;
}