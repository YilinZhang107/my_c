#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indexs;
        set<int> keys;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == key){
                indexs.push_back(i);
            }
        }
        for(auto i:indexs){
            for(int j=i; j>=0 && j>=i-k; j--){
                keys.insert(j);
            }
            for(int j=i; j<nums.size() && j<=i+k; j++){
                keys.insert(j);
            }
        }
        indexs.clear();
        for(auto i:keys){
            indexs.push_back(i);
        }
        sort(indexs.begin(), indexs.end());
        return indexs;
    }
};

int main(){
    vector<int> nums = {2,2,2,2,2};
    Solution s;
    nums = s.findKDistantIndices(nums,2,2);
    return 0;
}