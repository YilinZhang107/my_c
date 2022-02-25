#include<stdio.h>
int main()
{
    int number,i,guo,a[100];
    long x;
    int pan(long x);   
    scanf("%d",&number);
    for(i=0;i<number;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<number;i++)
    {
        guo=pan(a[i]);
        if(guo!=-1)
        printf("%d\n",guo);
        else
        printf("no\n");
    }
    return 0;
}


int pan(long x)
{
	int a[10],b,c,i,y,sum=0,guo;
	y=x;
	i=0;
	c=x;
	while(i<=9)             
	{
		i++;
		c=c/10;
		if(c==0)break;
	}
	c=i;
	for(i=0;i<=c;i++)        
	{
		b=y%10;
		a[i]=b;
		y=y/10;
		sum=sum+b;
	}
	y=0;
	for(i=0;i<=c;i++)        
	{
		b=a[i];
		y=y+b;
        if(i==c-1)break;
		y=y*10;
	}
	if(x==y)          
	guo=sum;
	else
	guo=-1;
	return (guo);
 } 
