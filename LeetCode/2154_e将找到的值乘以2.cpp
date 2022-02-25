#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(count(nums.begin(), nums.end(), original)){//自己写,直接用容器的count也很快
            original *= 2;
        }
        return original;
    }

    int findFinalValue_2(vector<int>& nums, int original) {//哈希实现
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) {
            original *= 2;
        }
        return original;
    }

};