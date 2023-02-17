#include<bits/stdc++.h>
using namespace std;
//按照每一位乘上9*8*7*6...这样累加
//注意判断是否要减1,(应该是前面出现过的就减1?)
class Solution {
public:
    int countSpecialNumbers(int n) {
        int t = n,wei = 0;
        int ans = 0;
        vector<int> num;
        while(t!=0){
            wei++;
            num.push_back(t%10);
            t/=10;
        }
        
        for(int i=wei; i>0; i++){
            ans += num[i]
        }
        return ans;
    }

    int cnt(int n){
        int ans=1;
        int cheng = 9;
        for(int i=0;i<n;i++){
            ans *=cheng;
            cheng--;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.cnt(3);
    return 0;
}