#include<bits/stdc++.h>
using namespace std;

//1.14优先队列应用

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;   
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top(); 
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    Solution s;
    vector<vector<int> > pairs = s.kSmallestPairs(nums1, nums2, 3);
    for(auto i = pairs.begin(); i != pairs.end(); i++){
        cout<<'['<<(*i)[0]<<','<<(*i)[1]<<']'<<endl;
    }
    return 0;
}