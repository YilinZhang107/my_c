#include<bits/stdc++.h>
using namespace std;

//73场双周赛
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> targets;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == key){
                if(targets.count(nums[i+1]) == 0)
                    targets.insert(make_pair(nums[i+1], 0));
                else
                    targets[nums[i+1]]++;
            }
        }
        unordered_map<int,int>::iterator max = targets.begin();
        for(auto i=targets.begin(); i!=targets.end(); i++){
            if(i->second > max->second)
                max = i;
        }
        return max->first;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,2,2,2,3};
    cout<<s.mostFrequent(nums, 2);
    return 0;
}