int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
bool st[N];   // 存储每个点的最短路是否已经确定，若确定则st[i]=true;


int Dijkstra()
{
    memset(dist,0x3f,sizeof dist);//除1号结点外，其他均初始为无穷大
    dist[1]=0;
    for(int i=0;i<n;i++) //n次迭代，每次寻找不在s中距离最近的点t
    {
        int t=-1;// 便于更新第一个点
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[j]<dist[t])) 
                t=j;
        st[t]=true;  //将t加到s中
        for(int j=1;j<=n;j++)  //用t更新其他点的距离
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==0x3f3f3f3f) 
        return -1; //路径不存在
    else return 
        dist[n];
}
