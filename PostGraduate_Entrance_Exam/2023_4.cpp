#include<bits/stdc++.h>
using namespace std;

// 图的深度优先遍历
int vis[10005]={0}; //是否被访问
vector<vector<int>> e;
int n, e_num, hasDir, beginInd; 


void dfs(int now){
    if(vis[now])
        return;
    vis[now]=1;
    cout<<now+1<<"-->";
    for(int i=0; i<n; i++){
        if (e[now][i]==1 && vis[i]==0){
            dfs(i);
        }
    }

}

int main(){
    cin>>n>>e_num>>hasDir>>beginInd;
    for(int i=0; i<n; i++){
        vector<int> t(n,0);
        e.push_back(t);
    }
    // int e[10005][10005]={0};
    for(int i=0; i<e_num; i++){
        int in,out;
        cin>>in>>out;
        e[in-1][out-1] = 1;
        if(hasDir)
            e[out-1][in-1] = 1;
    }

    dfs(beginInd-1);

    return 0;

}   