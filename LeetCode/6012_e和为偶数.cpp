#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countEven(int num) {
        int number = 0;
        for(int i=1; i<=num; i++){
            if(isOu(i))
                number++;
        }
        return number;
    }

    bool isOu(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num/=10;
        }
        if(sum % 2 == 0)
            return true;
        else
            return false;
    }
};


int main(){
    Solution s;
    cout<<s.countEven(30);
}