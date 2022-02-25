#include<stdio.h>

int main()
{
    char a[100];
    fgets(a,6,stdin);//stdin表示从标准输入（键盘）读入字符，6表示读入的字符个数（包含一个回车，
    printf("%s\n",a);                       //所以实际读入5个字符）
                                                 
                          //注意！当输入的字符数不够n值时，会自动在末位添加一个换行符
    char *pa;
    pa=a;
    fgets(pa,9,stdin);//利用指针进行输入
    printf("%s",a);
    return 0;  


}