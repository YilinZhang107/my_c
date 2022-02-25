// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include<bits/stdc++.h>
using namespace std;

bool g_InvalidInput = false;//全局变量用于判断是否出错

bool equal(double n1, double n2){
    //浮点数精度设置
    const double EPSINON = 0.00000001;
    double equalZero = n1 - n2;
    if(equalZero>EPSINON || equalZero<(-EPSINON))
        return false;
    else
        return true;
}

//这是logN复杂度的算法,也可以用循环的算法
double PowerWithUnsignedExponent(double base, int absExpoent){
    if(absExpoent==0)
        return 1;
    if(absExpoent==1)
        return base;

    double result = PowerWithUnsignedExponent(base, absExpoent>>1);//右移一位相当于除以2
    result *= result;//计算次方的公式, x^n = x^n/2 * x^n/2
    if((absExpoent & 1) == 1)//是奇数
        result *= base;
    return result;
}

double Power(double base, int exponent){
    
    if(equal(base, 0.0) && exponent<0){
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) exponent;
    if(exponent<0)
        absExponent = (unsigned int)(-1*exponent);
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent<0)//负数次方
        result = 1.0/result;        
    return result;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;
}
