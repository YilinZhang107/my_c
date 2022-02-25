#include<bits/stdc++.h>
using namespace std;

//还应该再加一点, 最多只会有1个数, 找到后可以及早退出

class Solution{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNums;
        for(int i=0; i<matrix.size(); i++){
            //求最小元素下标
            int minPosition = min_element(matrix[i].begin(), matrix[i].end())-matrix[i].begin();
            bool isMax = true;
            for(int j=0; j<matrix.size(); j++){
                if(matrix[j][minPosition] > matrix[i][minPosition]){
                    isMax = false;
                    break;
                }
            }
            if(isMax){
                luckyNums.push_back(matrix[i][minPosition]);
                break;//最多只会有1个数, 找到后可以及早退出
            }
        }
        return luckyNums;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> result = s.luckyNumbers(matrix);
    for(auto i=result.begin(); i!=result.end(); i++){
        cout<<*i<<endl;
    }
    return 0;
}