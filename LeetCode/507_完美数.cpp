//对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
//给定一个 整数 n， 如果是完美数，返回 true，否则返回 false

#include<bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num) {
    int sum = 0;
    for(int i=1;i<=num/2; i++){
        if(num%i==0)
            sum += i;
    }
    if(sum==num)
        return true;
    else
        return false;
}

bool checkPerfectNumber_2(int num) {
    if (num==1)
        return false;
    int sum = 0;
    for(int i=2;i*i<=num; i++){
        if(num%i==0){
            sum += i;
            if(i*i<num)
                sum += num/i;
        }
        
    }
    if(sum==num)
        return true;
    else
        return false;
}