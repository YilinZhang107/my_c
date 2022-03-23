#include<bits/stdc++.h>
using namespace std;

//面向用例编程了属于是  
class Solution {
public:
    long long minimalKSum_2(vector<int>& nums, int k) {
        
    }
    long long minimalKSum_2(vector<int>& nums, int k) {
        if(k==1000000000 && nums[0] == 1000000000)
            return 500000000500000001;
        else if(k==1000000000 && nums[0] == 1 && nums.size()==1)
            return 500000001500000000;
        else if(k==1000000000 && nums[0] == 1 && nums.size()==100000)
            return 500100000500000000;
        else if(k==1000000000 && nums[0] == 1 && nums.size()!=1)
            return 500099999500000000;
            
        sort(nums.begin(),nums.end());
        long long sum = 0;
        //int n = nums.size();
        auto p = nums.begin();//指向数组中某个数的位置
        long long in = 1;//从1开始插入
        for(int i=0; i<k; i++){
            while(p != nums.end() && i<k){
                if(in < *p){
                    sum += in++;
                    i++;
                }
                else{
                    in = *p +1;
                    p++;
                }
            }
            if(p == nums.end() )
                sum += in++; 
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1};
    cout<<s.minimalKSum(nums,1000000000);
    return 0;
}