#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> nums2 = nums;
        int ans1 =0, ans2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(i & 1){//ji
                while(nums[i-1] >= nums[i]){
                    nums[i-1]--;
                    ans1++;
                }
                while(i+1<nums.size() && nums[i+1] >= nums[i]){
                    nums[i+1]--;
                    ans1++;
                }
                i++;
            }
        }
        

        for(int i=0; i<nums2.size(); i++){
            if(!(i&1)){//ou
                while(i-1 >=0 && nums2[i-1] >= nums2[i]){
                    nums2[i-1]--;
                    ans2++;
                }
                while(i+1<nums2.size() && nums2[i+1] >= nums2[i] ){
                    nums2[i+1]--;
                    ans2++;
                }
                i++;
            }
        }
        ans1  = min(ans1, ans2);
        return ans1;

    }
};



int main(){

}