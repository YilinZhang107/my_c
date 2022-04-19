#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;

//傻逼题, 父母也可能是后文输入的情侣

struct man{
    char sex;
    int fa=-1,ma=-1;
}uf[100005];
int vis[100005];
bool flag = true;

void dfs(int v,int dai){
    if(dai>5 || v==-1)
        return;
    if(vis[v]){
        flag = 0;
        return;
    }
    vis[v] = 1;
    dai++;  
    dfs(uf[v].fa,dai);
    dfs(uf[v].ma,dai);
}

int main(){
    cin>>n;
    int i,j,t,father,mather;
    char c;
    for(i=0;i<n;i++){
        cin>>t>>c>>father>>mather;
        uf[t].sex =c;
        if(father != -1){
            uf[t].fa = father;
            uf[father].sex = 'M';
        }
        if(mather != -1){
            uf[t].ma = mather;
            uf[mather].sex = 'F';
        }
    }
    cin>>n;
    int a,b;
    for(i=0;i<n;i++){
        cin>>a>>b;
        if(uf[a].sex == uf[b].sex){
            cout<<"Never Mind"<<endl;
            continue;
        }
        memset(vis,0,sizeof(vis)); 
        flag = true;
        dfs(a,1);
        dfs(b,1);

        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}