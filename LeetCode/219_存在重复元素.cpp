#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class Solution {
public:
    //用哈希表解决
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> dictionary;
        int length = nums.size();
        for(int i=0;i<length;i++){
            if(dictionary.count(nums[i]) && i-dictionary[nums[i]]<=k){
                return true;
            }
            dictionary[nums[i]] = i;
        }
        return false;
    }

    //用哈希表解决
    bool containsNearbyDuplicate_2(vector<int>& nums, int k) {
        unordered_map<int,int> dictionary;
        int length = nums.size();
        for(int i=0;i<length;i++){
            int n = nums[i];
            if(dictionary.count(n) && i-dictionary[n]<=k){
                return true;
            }
            dictionary[n] = i;
        }
        return false;
    }

    //自己写的,超时了
    bool containsNearbyDuplicate_false(vector<int>& nums, int k) {
        //小于k则只要有重复数就true
        if(nums.size() <= k){
            sort(nums.begin(),nums.end());
            for(auto i=nums.begin(); i != nums.end()-1; i++){
                if(*i == *(i+1))
                    return true;
            }
            return false;
        }
        //大于k则从每个数之后查找k个数,看是否有相同
        else{
            for(auto i=nums.begin(); i!=nums.end(); i++){
                for(int j=1; j<=k && i+j != nums.end(); j++){
                    if(*i == *(i+j))
                        return true;
                }
            }
            return false;
        }
    }
};

int main(){
    Solution s;
    bool result;
    double start = GetTickCount();
    vector<int> nums = {1,2,3,1,2,3};
    for(int i=0; i<1000000;i++)
        result = s.containsNearbyDuplicate(nums,2);
    double end = GetTickCount();
    cout<<"time:"<<end-start<<endl;
    
    start = GetTickCount();
    for(int i=0; i<1000000
    ;i++)
        result = s.containsNearbyDuplicate_2(nums,2);
    end = GetTickCount();
    cout<<"time:"<<end-start<<endl;
    return 0;

}