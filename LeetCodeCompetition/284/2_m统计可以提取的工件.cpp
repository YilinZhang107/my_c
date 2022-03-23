#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool> > isDig;
        isDig.resize(n, vector<bool>(n));
        //进行挖掘
        for(int i=0; i<dig.size(); i++){
            isDig[dig[i][0]][dig[i][1]] = true;
        }

        int sum = 0;
        for(auto i=artifacts.begin();i!=artifacts.end(); i++){
            if((*i)[0] == (*i)[2] && (*i)[1] == (*i)[3]){
                //一块
                if(isDig[(*i)[0]][(*i)[1]])
                    sum++;
            }
            else if((*i)[0] == (*i)[2] && (*i)[1] != (*i)[3] ){
                //横着
                bool out = true;
                for(int j=(*i)[1]; j<=(*i)[3]; j++){
                    if( !isDig[(*i)[0]][j] ){
                        out=false;
                        break;
                    }
                }
                if(out)
                    sum++;
            }
            else if((*i)[0] != (*i)[2] && (*i)[1] == (*i)[3] ){
                //竖着
                bool out = true;
                for(int j=(*i)[0]; j<=(*i)[2]; j++){
                    if( !isDig[j][(*i)[1]] ){
                        out=false;
                        break;
                    }
                }
                if(out)
                    sum++;
            }
            else{
                //4块
                if(isDig[(*i)[0]][(*i)[1]] &&isDig[(*i)[0]][(*i)[1]+1] && isDig[(*i)[2]][(*i)[3]] && isDig[(*i)[2]][(*i)[3]-1])
                    sum++;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<vector<int>> artifacts = {{0,0,0,0},{0,1,1,1}};
    vector<vector<int>> dig = {{0,0},{0,1}};
    cout<<s.digArtifacts(2,artifacts,dig);
    return 0;
}