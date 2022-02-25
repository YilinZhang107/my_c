//递增的三元子序列

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //双向遍历, 时间O(n), 空间O(n)
    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        //分别存储左边到某位为止最小的数,和右边最大的数
        int *leftMin = new int[length];
        int *rightMax = new int[length];
        int temp = INT_MAX;
        for(int i = 0; i < length; i++){
            if(nums[i] < temp)
                temp = nums[i];
            leftMin[i] = temp;
        }
        temp = INT_MIN;
        for(int i = length-1; i >= 0; i--){
            if(nums[i] > temp)
                temp = nums[i];
            rightMax[i] = temp;
        }
        for(int i=1; i<length-1; i++){
            if(leftMin[i-1] < nums[i] && nums[i] < rightMax[i+1])
                return true;
        }
        return false;
    }

    //只用存储两个数,贪心
    bool increasingTriplet_1(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for(int i : nums){
            if(i <= n1)
                n1 = i;
            else if(i <= n2)
                n2 = i;
            else
                return true;
        }
        return false;
    }
};


int main(){
    vector<int> nums = {0,4,2,1,0,-1,-3};
    Solution s;
    cout<<s.increasingTriplet_1(nums);
    return 0;
}