#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        auto sumOfOne = [](int n)->int {
            int sum=0;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            return sum;
        };
        
        while(num > 9 )
            num = sumOfOne(num);
        return num;
    }
    //数学方法
// 原数: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
// 偏移: 0 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 
// 取余: 0 1 2 3 4 5 6 7 8  0  1  2  3  4  5  6  7  8  0  1  2  3  4  5  6  7  8  0  1  2  
// 数根: 1 2 3 4 5 6 7 8 9  1  2  3  4  5  6  7  8  9  1  2  3  4  5  6  7  8  9  1  2  3 
    int addDigits_1(int num) {
        return (num-1)%9 +1 ;
    }
};

int main(){
    Solution s;
    cout<<s.addDigits(38);
    
    return 0;
}