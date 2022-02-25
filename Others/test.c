#include<stdio.h>
int main()
{
  int a,i,b;
  scanf("%d",&a);
  for(i=0;i<10;i++)
  b=1+a++;
  printf("%d",a);
  return 0;
    
}