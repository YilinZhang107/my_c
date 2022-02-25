#include<bits/stdc++.h>
using namespace std;
/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。
*/
class Solution {
public:
    //最小堆
    int uglyNumber(int n){
        int factors[] = {2,3,5};
        priority_queue<long, vector<long>, greater<long>> heap;
        unordered_set<long> seen;//哈希集合用来去重
        heap.push(1);
        seen.insert(1);
        int ugly=0;
        for(int i=0; i<n; i++){
            long curr = heap.top();
            heap.pop();
            ugly = (int)curr;
            for(int factor: factors){
                long next = factor*curr;
                if(!seen.count(next)){
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }

};

int main(){
    
    Solution s;
    cout<<s.nthUglyNumber(10);
    return 0;
}