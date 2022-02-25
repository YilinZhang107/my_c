#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int week = n/7;
        int sum = 0;
        for(int i=1; i<=week; i++){
            for(int j=0; j<7; j++)
                sum += i+j;
        }
        for(int i=0; i<n%7; i++){
            sum += week+1+i;
        }
        return sum;
    }
};