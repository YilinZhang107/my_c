#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int num7 = 0, i=1;
        while(num) {//等价于num!=0
            num7 += num%7*i;
            num/=7;
            i*=10;
        }
        return to_string(num7);
    }
};


int main(){
    Solution s;
    cout<<s.convertToBase7(-7);
    return 0;
}