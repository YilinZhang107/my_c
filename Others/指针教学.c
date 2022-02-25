#include<stdio.h>
int main()
{
    char a='!';
    int i=0;
    char *pa=&a;
    int *pb=&i;
    float l;
    float *pc=&l;
    printf("%c\n",*pa);
    printf("%d\n",*pb);

    printf("%d\n",sizeof(pa));    //sizeof打出此类型所占字节
    printf("%d\n",sizeof(pb));
    printf("%d\n",sizeof(pc));
    
    printf("%p\n",pa);            //%p打印出16位地址
    printf("%p\n",pb);
    printf("%p\n",pc);

    return 0;
}