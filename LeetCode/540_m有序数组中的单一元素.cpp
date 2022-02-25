#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int onlyOnceNum(vector<int> &nums){
        int front = 0, back = nums.size()-1;
        int pNow = (front+back)/2;
        if(pNow%2 != 0)
            pNow++;
        while(front != back && !(nums[pNow] != nums[pNow-1] && nums[pNow] != nums[pNow+1])){
            //中间数和后一个相同,则单个数在后面
            if(nums[pNow] == nums[pNow+1]){
                front = pNow;
            }
            else{//不相同则在前面
                back = pNow;
            }
            pNow = (front+back)/2;
            if(pNow == 1){
                if(nums[0] == nums[1])
                    return nums[2];
                else
                    return nums[0];
            }
            if(pNow&1 == 1) //用与运算比%要快
                pNow++;
        }
        return nums[pNow];
    }
};

int main(){
    vector<int> nums = {1,1,2,2,3};
    Solution s;
    cout<<s.onlyOnceNum(nums);
    return 0;
}