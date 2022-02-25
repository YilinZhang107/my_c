#include<stdio.h>
int main()
{
    char n[50] = {0};
    int i = 0,sum = 0;
    for(i ; i < 50; i++){
        scanf("%c",&n[i]);
        if(n[i]==10)
            break;
         sum = sum + n[i]-48; 
    }
    int pan = 0;
    if(sum%3 == 0)
        pan =1;
    printf("%d %d",sum,pan);
}