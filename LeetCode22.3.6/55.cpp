#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int energy = 1;
        for(int i=0; i<nums.size()-1; i++){
            energy--;//走一步
            energy = max(energy, nums[i]);
            if(energy == 0)
                return false;
        }
        return true;
    }
};


int main(){

}