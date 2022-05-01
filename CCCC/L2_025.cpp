#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;

vi edges[10005];
int ocp[10005];

bool dfs(){
    bool yes = true;
    for(int i=1;i<=n;i++){
        if(!ocp[i]){
            for(int j=0;j<edges[i].size();j++){
                if(!ocp[edges[i][j]]) return false;
            }
        }
    }
    return yes;
}

int main(){
    cin>>n>>m;
    int a,b;
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    cin>>k;
    int  t,c;
    for(int i=0;i<k;i++){
        memset(ocp,0,sizeof(ocp));
        cin>>t;
        while(t--){
            cin>>c;
            ocp[c] = 1;
        }
        if(dfs()){
            cout<<"YES"<<endl;
        }else
            cout<<"NO"<<endl;
    }
    return 0;
}