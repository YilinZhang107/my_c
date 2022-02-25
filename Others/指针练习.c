#include<stdio.h>
int main()
{
    char a[]={"helloworld"};
    char *pa=a;
   //pa=a;      当上一行为 char *pa时取注释号                       //不可为*pa=a或pa=*a
                      
    printf("%c\n",*(pa+1));
    printf("%c\n",*(a+1));
    printf("%s\n",pa);
    printf("%p\n",pa);
    printf("%p\n",pa+1);


    return 0;
}