#include<stdio.h>
int main()
{
    char a[80];
    int q,number=0,i,j,t;
    for(q=1;q>0;q++)
    {
    for(i=0;i<80;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]==10||a[i]==32)break;  
    }
    number=i;
    if(a[i]==32)break;          
    for(i=1;i<number;i++)           
      for(j=0;j<number-i;j++)
          if(a[j]>a[j+1])
          {
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
          }
    for(i=0;i<number;i++)      
    printf("%c",a[i]);
    printf("\n");
    }
    return 0;
}
