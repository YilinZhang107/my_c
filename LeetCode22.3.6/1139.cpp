#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int glen,gwide;//gird's 长和宽
        glen = grid.size();
        gwide = grid[0].size();
        int ans = min(glen,gwide); //max len
        int a=0,b=0, flag = 0;
        while(1){
            for(a=0;a+ans <= glen; a++){
                for(b=0; b+ans<=gwide; b++){
                    flag = hasSquare(grid, a,b,ans);
                    if(flag==1)
                        return ans*ans;  
                }
            }  
            ans--;
        }
        return ans*ans;
    }

    //检查在（a，b）点是否存在边长为len的正方形
    int hasSquare(vector<vector<int>> &grid, int a, int b, int len){
        for(int i=b; i<b+len; i++){
            if(grid[a][i] != 1)
                return 0;
        }
        for(int i=a; i<a+len; i++){
            if(grid[i][b] != 1)
                return 0;
        }
        for(int i=a; i<a+len; i++){
            if(grid[i][b+len-1] != 1)
                return 0;
        }
        for(int i=b; i<b+len; i++){
            if(grid[a+len-1][i] != 1)
                return 0;
        }
        return 1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,1,0,0}};
    cout<<s.largest1BorderedSquare(grid);
    return 0;
}
