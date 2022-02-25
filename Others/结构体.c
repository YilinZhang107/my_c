#include<stdio.h>
int main()
{
    struct Student
    {
        int mun;
        char a[10];
        char sex;
    };
    struct Student s1={00001,"zhang",'M'};
    printf("NO.%d\nName:%s\nSex:%c\n",s1.mun,s1.a,s1.sex);
    return 0;   
}