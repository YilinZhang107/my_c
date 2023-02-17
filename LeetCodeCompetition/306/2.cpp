#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> score(edges.size(),0);
        for(int i=0;i<edges.size(); i++){
            score[edges[i]] += i;
        }
        long long max = 0, ans = 0;
        for(int i=0;i<score.size();i++){
            if(score[i] > max){
                max = score[i];
                ans = i;
            }
        }
        return ans;
    }
};