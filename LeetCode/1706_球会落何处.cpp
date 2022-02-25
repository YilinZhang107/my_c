#include<bits/stdc++.h>
using namespace std;

//直接模拟即可
class Solution{
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> target;
        int rows = grid.size(), columns = grid[0].size();
        //从每一列的顶部出发
        for(int i=0; i<columns; i++){
            int column = i;
            //每一列都从第一行出发
            for(int j=0; j<rows; j++){
                //向右下滚
                if(grid[j][column] == 1){
                    if(column+1<columns && grid[j][column+1] == 1)
                        column++;
                    else{
                        target.push_back(-1);
                        break;
                    }
                }//向左下滚
                else{
                    if(column-1>-1 && grid[j][column-1] == -1)
                        column--;
                    else{
                        target.push_back(-1);
                        break;
                    }
                }
            }
            if(target.size() != i+1)
                target.push_back(column);
        }   
        return target;
    }
};

int main(){
    Solution s;
    vector<vector<int> > grid = {{1,1,1,-1,-1},
                                {1,1,1,-1,-1},
                                {-1,-1,-1,1,1},
                                {1,1,1,1,-1},
                                {-1,-1,-1,-1,-1}};
    vector<int> result = s.findBall(grid);
    return 0;
}