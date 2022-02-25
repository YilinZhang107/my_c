//逃离大迷宫
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    //在包围圈中
    static constexpr int BLOCKED = -1;
    //不在包围圈中
    static constexpr int VALID = 0;
    //无论在不在包围圈中,但在n(n-1)/2步探索的过程中经过了target
    static constexpr int FOUND = 1;
    
    static constexpr int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    static constexpr int BOUNDARY = 1000000;

public:
    bool isEscapePossible(vector<vector<int> >& blocked, vector<int>& source, vector<int>& target){
        //只有1或0个block时,一定能到达
        if(blocked.size() < 2)
            return true;
        
        auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o)-> size_t{
            auto& [x, y] = o;
            return fn((long long)x << 20 | y);
        };
    }

};