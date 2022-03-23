#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum = 0;
        for(int i=0; i<n-1; i++){
            int minNum = nums[i], maxNum = nums[i];
            for(int j=i+1; j<n; j++){
                minNum = min(minNum, nums[j]);
                maxNum = max(maxNum, nums[j]);
                sum += maxNum-minNum; 
            }
        }
        return sum;
    }

    //还有一个单调栈算法
};


int main(){
    Solution s;
    vector<int> nums = {4,-2,-3,4,1};
    cout<<s.subArrayRanges(nums);
    
    return 0;
}