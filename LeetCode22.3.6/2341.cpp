#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int index[105];
        for(int i=0;i<=100; i++){
            index[i]=0;
        }
        for(int i=0;i<nums.size(); i++){
            index[nums[i]]++;
        }
        int pairs=0, last = 0;
        for(int i=0;i<=100;i++){
            if(index[i] != 0 && index[i]%2 != 0 )
                last++;
            pairs += index[i]/2;
        }
        vector<int> ans;
        ans.push_back(pairs);
        ans.push_back(last);
        return ans;
    }
};

int main(){
    
}