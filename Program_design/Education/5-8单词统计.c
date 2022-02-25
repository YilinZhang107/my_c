#include<stdio.h>
int main()
{
    char a[100];
    int number=0,i;
    for(i=0;i<100;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]==10)break;
        if(a[i]==32)number++;
    }
    printf("%d",number+1);
    
    return 0;


}