#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        vector<int> ans;
        priority_queue<pair<int, int> > pq;
        for(map<int, int>::iterator i =mp.begin(); i!= mp.end(); i++){
            //first->key   second->value
            pair<int, int> t = make_pair(i->second, i->first);
            pq.push(t);
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
};


int main(){
    Solution s;
    vector<int> v = {1,1,1,2,2,3};
    v = s.topKFrequent(v, 2);
    for(auto i = v.begin(); i!= v.end(); i++){
        cout<<*i<<" ";
    }
    
}