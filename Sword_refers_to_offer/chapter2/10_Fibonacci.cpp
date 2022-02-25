#include<bits/stdc++.h>
using namespace std;


// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

//循环的写法, 递归有太多浪费
long long Fibonacci(unsigned n){
    long long N;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else{
        long long one = 0, two = 1;
        for(unsigned i=2; i<=n; i++){
            N = one + two;
            one = two;
            two = N;
        }
    }
    return N;
}

// ====================测试代码====================
void Test(int n, int expected)
{
     if(Fibonacci(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);
    /*
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

    if(Fibonacci_Solution3(n) == expected)
        printf("Test for %d in solution3 passed.\n", n);
    else
        printf("Test for %d in solution3 failed.\n", n);
    */
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}