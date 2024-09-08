#include<bits/stdc++.h>
using namespace std;

int fa[1001];

int find(int x){
    if(fa[x] == x)
        return x;
    return fa[x] = find(fa[x]); //路径压缩
}

int main(){
    int n, m;
    while(cin>>n){
        if(n == 0)
            return 0;
        cin>>m;
        for(int i=1; i<=n; i++)
            fa[i] = i;
        int x1, x2;
        for(int i=0; i<m; i++){
            cin>>x1>>x2;
            fa[find(x1)] = find(x2);
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(fa[i] == i)
                cnt++;
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}