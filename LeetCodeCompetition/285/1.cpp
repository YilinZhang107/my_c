#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int sum = 0;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i-1] == nums[i])
                continue;
            int lo=i-1;
            int hi = i+1;
            while(hi<nums.size()-1 && nums[hi]==nums[i]){
                hi++;
            }
            if((nums[i]>nums[lo]&&nums[i]>nums[hi]) ||(nums[i]<nums[lo]&&nums[i]<nums[hi]))
                sum++;
        }
        return sum;
    }
};

int main(){
    vector<int> nums = {6,6,6};
    Solution s;
    cout<<s.countHillValley(nums);
    return 0;
}