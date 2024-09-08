#include<bits/stdc++.h>
using namespace std;

// dijsktra
// 边带权值, 权值非负, 从某点出发到xx点的最短路

int dis[10005]; //从s点出发,到所有点的距离, 初始值为INT_MAX
int vis[10005]; //访问过这个点
int e[10005][10005];
int n,m,s;

void dij(int start){
    dis[start] = 0;
    int minDis, now; //从当前距离最近的点开始
    for(int i=1; i<=n; i++){
        minDis = INT_MAX;
        for(int j=1; j<=n; j++){
            if(!vis[j] && minDis > dis[j]){
                minDis = dis[j];
                now = j;
            }
        }
        vis[now] = 1;
        for(int j=1; j<=n; j++){
            //                                  1        2         4
            if(!vis[j] && e[now][j] != -1 && e[now][j]+minDis < dis[j]){
                dis[j] = e[now][j]+minDis;
            }
        }
    }
}

int main(){
    cin>>n>>m>>s;
    for(int i=1; i<=n; i++)
        dis[i] = INT_MAX;
    for(int i=1; i<=n; i++)
        vis[i] = 0;
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++)
            e[i][j] = -1;
    }

    int u,v,w;
    for(int i=0; i<m;i++){
        cin>>u>>v>>w;
        if(e[u][v] != -1){
            e[u][v] = min(w, e[u][v]);
        }
        else
            e[u][v] = w;
    }
    dij(s);
    for(int i=1; i<=n; i++){
        cout<<dis[i]<<" ";
    }
}
