#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(auto i=bits.begin(); i!=bits.end(); i++){
            if(*i == 0 && i+1 == bits.end())
                return true;
            if(*i == 1)
                i++;
        }
        return false;
    }

    //官解
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size(), i = 0;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }


};