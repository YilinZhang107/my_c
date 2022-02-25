#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //暴力递归解法超时
    double knightProbability_my(int n, int k, int row, int column) {
        double probability = move(n,k,row,column, 1.0);
        return probability;
    }
    //k:剩余步数 
    double move(int n, int k, int row, int column, double probability){
        if(row<0 || row>=n || column<0 || column>=n)
            return 0;
        if(k>0){
            k--;
            probability = move(n, k, row+2, column-1, probability/8) +
                        move(n, k, row+1, column-2, probability/8) +
                        move(n, k, row-1, column-2, probability/8) +
                        move(n, k, row-2, column-1, probability/8) +
                        move(n, k, row-2, column+1, probability/8) +
                        move(n, k, row-1, column+2, probability/8) +
                        move(n, k, row+1, column+2, probability/8) +
                        move(n, k, row+2, column+1, probability/8); 
        }
        return probability;
    }

    //用数组存储一部分遍历过的结果,记忆搜索
    double knightProbability(int n, int k, int row, int column) {
        //存储在某格子上还剩k步时出不去的概率
        vector<vector<vector<double> > > probabilitys(k+1, vector<vector<double>>(n,vector<double>(n))); 
        return dfs(n,k,row,column, probabilitys);
    }
    //k:剩余步数 
    double dfs(int n, int k, int row, int column, vector<vector<vector<double>>> &probabilitys){
        if(row<0 || row>=n || column<0 || column>=n)
            return 0;
        if(k==0)
            return 1.0;
        if(probabilitys[k][row][column] != 0)
            return probabilitys[k][row][column];
        if(k>0){
            k--;
            probabilitys[k+1][row][column] = 
                dfs(n, k, row+2, column-1, probabilitys)/8 +
                dfs(n, k, row+1, column-2, probabilitys)/8 +
                dfs(n, k, row-1, column-2, probabilitys)/8 +
                dfs(n, k, row-2, column-1, probabilitys)/8 +
                dfs(n, k, row-2, column+1, probabilitys)/8 +
                dfs(n, k, row-1, column+2, probabilitys)/8 +
                dfs(n, k, row+1, column+2, probabilitys)/8 +
                dfs(n, k, row+2, column+1, probabilitys)/8; 
        }
        return probabilitys[k+1][row][column];
    }
};

int main(){
    Solution s;
    cout<<s.knightProbability(8,30,6,4);
    return 0;
}