#include<stdio.h>
int main()
{
    int a[10];
    int *pa=a;
    for(pa=a;pa<(a+10);pa++)   //注意此处循环的格式
     scanf("%d",pa);
    pa=a;                //此句也可加在下一行
    for(;pa<(a+10);pa++)
     printf("%d ",*pa);
    return 0;
}