#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // stl
        // priority_queue
        //sort nlogn
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        while(k--  > 1){
            pq.pop();
        }
        return pq.top();

    }
};

int main(){
    Solution s;
    vector<int> v = {3,2,1,5,6,4};
    cout<<s.findKthLargest(v,2);
}