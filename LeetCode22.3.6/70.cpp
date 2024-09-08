#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int x,y,z;
        x = 1;
        y = 1;
        z = 1;
        for(int i=2; i<=n; i++){
            x = y;
            y =z;
            z = x+y;
        }
        return z;
    }
};


int main(){
    
}