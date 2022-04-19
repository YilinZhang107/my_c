#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;
int v,e;
vi edges[505];
int p[505];
set<int> color;
bool judge(){
    for(int i=1;i<=v;i++){
        for(int j=0;j<edges[i].size();j++){
            if(p[i] == p[edges[i][j]]) return false;
        }
    }
    return true;
}

int main(){
    cin>>v>>e>>k;
    int a,b;
    int max = -1;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i=1;i<=v;i++){
        if(edges[i].size()>max) max = edges[i].size();
    }
    int flag = 1;
    if(max > k) flag = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        color.clear();
        for(int j=1; j<=v;j++){
            scanf("%d", &p[j]);
            color.insert(p[j]);
        }
        if(flag && color.size() == k){  //真傻逼, 颜色必须等于k种
            if(judge()) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}