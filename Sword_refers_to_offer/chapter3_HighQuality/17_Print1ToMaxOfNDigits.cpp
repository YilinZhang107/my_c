// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include<bits/stdc++.h>
using namespace std;

void PrintNumber(char* num){
    while(*num == '\0' || (*num == '0'&& *(num+1) != '\0'))
        num++;
    while(*num != '\0'){
        cout<<*num;
        num++;
    }
    cout<<' ';
    return;
}

void print1ToMaxOfNDigitsRecursively(char* num, int n, int pIndex){
    //修改到了最后一位就输出
    if(n == pIndex){
        PrintNumber(num);
        return;
    }
    for(int i=0; i<=9; i++){
        num[pIndex] = '0'+i;
        print1ToMaxOfNDigitsRecursively(num, n, pIndex+1);
    }
}


void Print1ToMaxOfNDigits_3(int n){
    //用字符数组储存
    char* num = new char[n+1]{'\0'};
    int pIndex = n;//记录现在输出到第几位
    for(int i=1; i<=n; i++){
        print1ToMaxOfNDigitsRecursively(num, n, n-i);
    }
    delete[] num;
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    //Print1ToMaxOfNDigits_1(n);
    //Print1ToMaxOfNDigits_2(n);
    Print1ToMaxOfNDigits_3(n);
    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
