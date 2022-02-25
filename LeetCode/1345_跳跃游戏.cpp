#include<bits/stdc++.h>
using namespace std;


//广度优先搜索
class Solution{
public:
    int minJumps(vector<int>& arr){
        unordered_map<int, vector<int>> idxSameValue;//存重复的数
        for(int i=0; i<arr.size(); i++){
            idxSameValue[arr[i]].push_back(i);
        }
        unordered_set<int> visitedIndex;//被检查过的下标
        queue<pair<int, int>> q;//搜索的队列
        q.emplace(0,0);
        visitedIndex.emplace(0);
        while(!q.empty()){
            auto [idx, step] = q.front();
            q.pop();
            if(idx == arr.size()-1){
                return step;
            }
            int v = arr[idx];
            step++;
            //相同数放进q中
            if(idxSameValue.count(v)){
                for(auto& i : idxSameValue[v]){
                    if(!visitedIndex.count(i)){
                        visitedIndex.emplace(i);
                        q.emplace(i, step);
                    }
                }
                idxSameValue.erase(v);
            }
            //后一个数
            if(idx + 1 < arr.size() && !visitedIndex.count(idx+1)){
                visitedIndex.emplace(idx+1);
                q.emplace(idx+1,step);
            }
            //前一个数
            if(idx - 1 >= 0 && !visitedIndex.count(idx-1)){
                visitedIndex.emplace(idx-1);
                q.emplace(idx-1, step);
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    Solution s;
    cout<<s.minJumps(arr);
    return 0;
}