#include<stdio.h>
int main()
{
   int x,i;
   scanf("%d",&x);
   if(x==0)
   printf("1");
   else if(x==1)
   printf("1");
   else 
   {
       for(i=2;i<=x;i++)
       if(x%i==0)break;
       if(i==x)
       printf("1");
       else 
       printf("0");
   }
   
   return 0;
}
