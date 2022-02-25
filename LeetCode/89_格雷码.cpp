/*
n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
第一个整数是 0
一个整数在序列中出现 不超过一次
每对 相邻 整数的二进制表示 恰好一位不同 ，且
第一个 和 最后一个 整数的二进制表示 恰好一位不同
给你一个整数 n ，返回任一有效的 n 位格雷码序列 。
*/


#include<bits/stdc++.h>
using namespace std;

//gray码公式, gray[n] = n xor(异或) n>>1
class Solution_1 {
public:
    vector<int> grayCode(int n) {
        vector<int> gray(1<<n);
        for(int i=0; i<(1<<n); i++){
            gray[i] = (i ^ (i>>1));
        }
        return gray;
    }
};
//对称构造法
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        gray.push_back(0);
        int head = 1;
        for(int i=0; i<n; i++){//大循环循环n次,总数为2^n个
            for(int j=gray.size()-1 ; j>=0; j--){//逆序
                gray.push_back(head + gray[j]);//对称构造
            }
            head = head<<1;//最前面的1左移一位
        }
        return gray;
    }
};


int main(){
    Solution s;
    vector<int> gray = s.grayCode(3);
    for(auto i=gray.begin(); i!=gray.end(); i++)
        cout<<*i;
    return 0;
}