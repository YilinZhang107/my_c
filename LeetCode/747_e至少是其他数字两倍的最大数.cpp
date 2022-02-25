#include<bits/stdc++.h>
using namespace std;
//遍历一遍,找出最大数和次大数即可
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = 0;
        int max = -1, mid = -1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > max){
                mid = max;
                max = nums[i];
                index = i;
            }
            else if(nums[i] > mid)
                mid = nums[i];
        }
        if(max < 2*mid && nums.size()>1)
            index = -1;
        return index;
    }
};


int main(){
    vector<int> nums = {3,6,1,0};
    Solution s;

    cout<<s.dominantIndex(nums);
    return 0;
}