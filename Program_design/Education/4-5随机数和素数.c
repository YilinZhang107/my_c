#include<stdio.h>
#include<stdlib.h>
int su(int x)
{
   int i,so;
   if(x==0)
   so=1;
   else if(x==1)
   so=1;
   else 
   {
       for(i=2;i<=x;i++)
       if(x%i==0)break;
       if(i==x)
       so=1;
       else 
       so=0;
   }
   
   return (so);
}
int main()
{
    int ou=0,ji=0,s=0,pan;
    int zhong,a[1500],i;
    scanf("%d",&zhong);
    srand(zhong);
    for(i=0;i<1500;i++)
    {
        a[i]=rand();
        if(a[i]%2==0)
        ou=ou+1;
        else
        ji=ji+1;
        pan=su(a[i]);
        if(pan==1)
        {s=s+1;}
    }
    printf("%d %d %d",ou,ji,s);
    return 0;
    
}