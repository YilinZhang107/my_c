#include<stdio.h>
int main()
{
    int x;
    char y,z;
    scanf("%d,%c,%c",&x,&y,&z);
    printf("%d %c %d",x+y+z,y+z,y+z);
    return 0;
}