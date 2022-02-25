#include<stdio.h>
int main()
{
  char a[10],fu=' ';
  int i,j,l,n[2]={0,0};
  for(i=0;i<2;i++)
  {
    scanf("%c",&a[i]);
    if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='%')//挑出运算符
     {
      fu=a[i];
      i=i-1;
      continue; 
     }
    if(a[i]==' ')i=i-1;
    else
    {
     for(j=1;j<10;j++)
      {                         
       scanf("%c",&a[i+j]);     //录入数字
       if(a[j+i]==' '||a[i+j]=='\n')break;
      }
    
     for(l=i;l<j+i;l++)
      {
       n[i]=n[i]+a[l]-48;
       n[i]=n[i]*10;
     }
    }
  }
  if(fu==' ')      //此处若前两个输入的是数字，则另外进行一次输入，输入符号
  scanf("%c",&fu);
  int sum;
  n[0]=n[0]/10;
  n[1]=n[1]/10;
  switch (fu)
  {
  case '+':sum=n[0]+n[1];break;
  case '-':sum=n[0]-n[1];break;
  case '*':sum=n[0]*n[1];break;
  case '/':sum=n[0]/n[1];break;
  case '%':sum=n[0]%n[1];break;
  }
  printf("%d",sum);
  return 0;
    
}