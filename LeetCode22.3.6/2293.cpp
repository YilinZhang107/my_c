#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
       
        while(n != 1){
            n/=2;
            for(int i=0; i<n; i++){
                if(i%2){//奇
                    nums[i] = max(nums[2*i], nums[2*i+1]);
                }
                else{
                    nums[i] = min(nums[2*i], nums[2*i+1]);
                }
            }
            
        }
        return nums[0];
    }
};

int main(){
    
    Solution s;
    vector<int> nums = {5,3,3,3,5,6,2,1};
    int ans = s.minMaxGame(nums);
    return 0;
}