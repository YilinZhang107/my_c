#include<bits/stdc++.h>
using namespace std;

int fa[5001];

int find(int x){
    if(fa[x] == x)
        return x;
    return find(fa[x]); //路径压缩
}

// int union(int x){

// }

int main(){
    int n,m,p,i;
    cin>>n>>m>>p;
    for(i=1; i<=n; i++)
        fa[i] = i;
    int x1,x2;
    for(i=0;i<m;i++){
        cin>>x1>>x2;
        fa[find(x1)] = find(x2);
    }
    for(i=0; i<p;i++){
        cin>>x1>>x2;
        if(find(x1) == find(x2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}