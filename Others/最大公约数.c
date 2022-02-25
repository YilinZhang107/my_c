#include<stdio.h>
int main()
{
	int z,x,y;
	int gong(int x,int y);
	scanf("%d %d",&x,&y);
	z=gong(x,y);
	printf("%d",z);
	return 0;
}
int gong(int x,int y)
{
	int t;
	if(x<0)x=-x;
	if(y<0)y=-y;
	if(x==0)t=y;
	else if(y==0)t=x;
	else
	{
	if(x>y)
    t=y;
    else
    t=x;   
    for(;t>0;t--)
    {
    	if(x%t==0&&y%t==0)break;
    }
    }
	return (t);
}

