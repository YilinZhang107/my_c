#include<bits/stdc++.h>
using namespace std;
//深度优先搜索
vector<vector<int> > edges;
vector<int> ans;
vector<bool> origin;
int originIndex;

void dfs(int index, vector<int>& temp){//序号, 当前路径长度
    if(edges[index].size() == 0)
        return;

    for(int i=0; i<edges[index].size(); i++){
        temp.push_back(edges[index][i]);
        if(temp.size() > ans.size()){
            ans = temp;
        }
        else if(temp.size() == ans.size() && temp<ans){
            ans = temp;
        }
        dfs(edges[index][i], temp);
        temp.pop_back();
        
    }
}

int main(){
    int n;
    cin>>n;
    origin.resize(n,true);
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        vector<int> t3;
        for(int j=0; j<t; j++){
            int t2;
            cin>>t2;
            t3.push_back(t2);
            origin[t2] = false;
        }
        sort(t3.begin(), t3.end());//排序一下以便求最小编号
        edges.push_back(t3);
    }
    
    for(int i=0;i<n;i++){
        if(origin[i]){
            originIndex = i;
            break;
        }
    }
    origin.resize(n,false);//之后用orgin记录是否遍历过这个节点
    vector<int> temp;
    temp.push_back(originIndex);
    dfs(originIndex, temp);
    
    int i = 0;
    cout<<ans.size()<<endl;
    for(i=0; i<ans.size(); i++){
        if(i==0)    
            cout<<ans[i];
        else
            cout<<" "<<ans[i];
    }
    return 0;
}