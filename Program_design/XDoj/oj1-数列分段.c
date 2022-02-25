#include<stdio.h>
int main()
{
    int max=1,n,i,x,y,now=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i==1)
        scanf("%d",&x);
        else
        {
            scanf("%d",&y);
            if (x!=y)
            now=now+1;
            x=y;
            
        }
    }
    printf("%d",now);
    return 0;
}