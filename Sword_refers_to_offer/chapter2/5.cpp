#include<bits/stdc++.h>
using namespace std;

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。


//在此过程中字符串会变长,应当意识到这个问题
//这样从后往前时间复杂度为N, 从前往后时间复杂度n^2
void ReplaceBlank(char *str, int length){
    if (str==nullptr)
        return ;
    
    int trueLength=0, blankNum = 0;
    int i=0,j=0;//两个指针的作用
    while(str[i]!='\0'){
        trueLength++;
        if(str[i]==' ')
            blankNum++;
        i++;
    } //计算长度和空格数量
    char *newStr =  new char[trueLength +1 +2*blankNum];
    strcpy(newStr,str);
    i=trueLength+2*blankNum;//后面的指针
    j=trueLength;//前面的指针
    while(i!=j) {//两指针会和时结束
        if(newStr[j]==' '){
            newStr[i] = '0';
            newStr[i-1] = '2';
            newStr[i-2] = '%';
            i -= 3;
            j --;
        }
        else{
            newStr[i] = newStr[j];
            i--;
            j--;
        }
    }
    //str = newStr;   这样不行
    strcpy(str,newStr);//把新数组复制回去, 可以从一开始就在老数组上操作
}

// ====================测试代码====================
void Test(char* testName, char *str, int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}