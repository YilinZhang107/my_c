#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        vector<int> t;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            t.clear();
            cnt = 0;
            for(int j=0; j+i<nums.size();j++){
                if(nums[i+j] % p == 0)
                    cnt++;
                if(cnt>k) break;
                t.push_back(nums[i+j]);
                ans.insert(t);
            }
        }
        return ans.size();
    }
};


int main(){
    Solution s;
    vector<int> vi = {1,2,3,4};
    cout<<s.countDistinct(vi,4,1);
    return 0;
}