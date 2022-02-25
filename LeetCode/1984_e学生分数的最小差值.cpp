#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDif = INT_MAX;
        for(int i=0, j=k-1; j<nums.size(); i++,j++){
            int t = nums[j] - nums[i];
            if(minDif > t)
                minDif = t;
        }
        return minDif;
    }
};


int main(){
    vector<int> nums = {9,4,1,7};
    Solution s;
    cout<<s.minimumDifference(nums, 2);
    return 0;
}