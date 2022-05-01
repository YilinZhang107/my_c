#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define bug(a) cout<<#a<<": "<<a<<endl
#define N 510
/*需要的数组
dis[] 初始点到这点距离
edges[][] 邻接矩阵
pre[]  前一个点
look[] 这个点有没有被访问过
其他具体分析
*/

int dis[N],edges[N][N] ,fire[N],rootCnt[N], pre[N],  fireSum[N];
int look[N];
int n,m,s,d;

void dijkstra(int s, int d){
    memset(dis, 0x3f, sizeof(dis));//这个数组的大小实际上是510*4(int为4)个字节
    dis[s] = 0;
    fireSum[s] = fire[s];
    rootCnt[s] = 1;
    for(int i=0;i<n;i++){
        int k = -1;
        for(int j=0; j<n;j++){
        	bug(dis[j]);
        	bug(dis[k]);
            if(!look[j] && (k == -1 || dis[j]<dis[k]))
                k = j;
        }
        look[k] = true;//一旦选出,这个dis[k]就是到k的最小距离
        for(int j=0;j<n;j++){
            if(dis[j] == dis[k]+edges[k][j]){
                rootCnt[j]+=rootCnt[k];
                if(fireSum[j] < fireSum[k] + fire[j]){
                    pre[j] = k;
                    fireSum[j] = fireSum[k]+fire[j];
                }
            }
            else if(dis[j] > dis[k]+edges[k][j]){
                pre[j] = k;
                dis[j] = dis[k]+edges[k][j];
                rootCnt[j] = rootCnt[k];
                fireSum[j] = fireSum[k] + fire[j];
            }
        }
    }
}
int main(){
    int t;
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++) scanf("%d", &fire[i]);
    memset(edges, 0x3f, sizeof edges);//和下面的两种写法都可以,0x3f可作最大值
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d %d",&a,&b,&t);
        edges[a][b] = t;
        edges[b][a] = t;
    }
    //init
   
    
    dijkstra(s,d);
    
    cout<<rootCnt[d]<<" "<<fireSum[d]<<endl;
    stack<int> path;
    t = d;
    while(t != s){//将路径倒过来输出
        path.push(t);
        t = pre[t];
    }
   path.push(t);
    while(path.size()>1){
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<d;
    return 0;
}
