#include<iostream>
using namespace std;

// 输入一个年份（大于 1582 的整数 ），
//判断这一年是否是闰年，如果是输出 1，否则输出 0。
int main(){
    int n;
    cin >> n;
    if((n%4==0&&n%100!=0)||(n%400==0))
        cout<< "1";
    else
        cout<< "0";
    return 0;
}                 