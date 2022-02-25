#include<stdio.h>
int pan(int a,int b,int c,int d,int e)
{
	if(a&&b&&c||a&&b&&d||a&&b&&e||a&&c&&d||a&&c&&e||a&&d&&e||b&&c&&d||b&&c&&e||b&&d&&e||c&&d&&e)
    return (1);
    else
    return (0);
}
int main()
{
	printf("请输入五人的表决意见:(以0或1表示反对或支持，每个数字间空一格)\n");
	int x,y,z,m,n;
	scanf("%d %d %d %d %d",&x,&y,&z,&m,&n);
	if(pan(x,y,z,m,n)==1)
	printf("表决通过");
	else
	printf("表决不通过"); 
	return 0;
}
