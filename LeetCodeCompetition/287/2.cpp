#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int competitor[100005] = {0};//0没参加比赛, 1直在赢,2输了一次, 3输了多次
        vector<int> noFail, loseOne;
        for(int i=0; i<matches.size(); i++){
            if(competitor[matches[i][0]] == 0)
                competitor[matches[i][0]] = 1;

            if(competitor[matches[i][1]] == 0)
                competitor[matches[i][1]] = 2;
            else if(competitor[matches[i][1]] == 1)
                competitor[matches[i][1]] = 2;
            else if(competitor[matches[i][1]] == 2)
                competitor[matches[i][1]] = 3;
        }   
        for(int i=0; i<100005; i++){
            if(competitor[i] == 1)
                noFail.push_back(i);
            else if(competitor[i] == 2)
                loseOne.push_back(i);
        }
        vector<vector<int> > ans;
        ans.push_back(noFail);
        ans.push_back(loseOne);
        return ans;
    }
};

int main(){
    Solution s;
   
    return 0;
}