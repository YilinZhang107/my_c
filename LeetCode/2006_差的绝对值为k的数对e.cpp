#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j]) == k)
                    sum++;
            }
        }
        return sum;
    }

    int countKDifference_2(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        unordered_map<int, int> cnt;
        for (int j = 0; j < n; ++j) {
            res += (cnt.count(nums[j] - k) ? cnt[nums[j] - k] : 0);
            res += (cnt.count(nums[j] + k) ? cnt[nums[j] + k] : 0);
            ++cnt[nums[j]];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,1};
    cout<<s.countKDifference_2(nums, 1);
    return 0;
}
