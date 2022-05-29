#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); ){
            int j=1;
            int cnt = 1;
            int t=0;
            if(i+j<nums.size())
                t = nums[i+j];
            
            while(i+j<nums.size() && nums[i+j] > nums[i]){
                if(nums[i+j] >= t){
                    cnt++;
                    t = nums[i+j];
                }
                j++;
            }
            if(ans < cnt) ans = cnt;   
            i += j;         
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {7,14,4,14,13,2,6,13};
    //7,14,4,14,13,2,6,13
    //10,1,2,3,4,5,6,1,2,3
    cout<<s.totalSteps(nums);
}