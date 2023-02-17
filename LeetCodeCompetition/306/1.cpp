#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
     
        for(int i=1 ;i<grid.size()-1; i++){
            vector<int> t;
            for(int j=1; j<grid.size()-1; j++){
                int max = -1;
                //set<int,greater<int>> s;
                for(int l=i-1;l<=i+1; l++){
                    for(int k=j-1; k<=j+1; k++){
                        if(grid[l][k] > max)
                            max = grid[l][k];
                    }
                }
                t.push_back(max);
            }
            ans.push_back(t);
        }
        return ans;
    }
};