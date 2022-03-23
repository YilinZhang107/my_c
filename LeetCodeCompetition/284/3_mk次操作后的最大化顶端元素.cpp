#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size() == 1 && (k&1)==1)
            return -1;
        if(k == 0)
            return nums[0];

        int n =nums.size();
        //大于栈长度一定返回最大数
        if(k>n)
            return *max_element(nums.begin(), nums.end());
        else if( k == n){
            return *max_element(nums.begin(), nums.end()-1);
        }
        else{
            *(nums.begin()+k-1) = 0;
            int maxNum = *max_element(nums.begin(), nums.begin()+k+1);
            return maxNum;
            /*
            if(maxIndex <= k)
                return nums[maxIndex];
            else
                return 
            */
            
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> nums = {11,18,17,79,1,2,3,4,5,6};
    cout<<s.maximumTop(nums,3);
    
    return 0;
}