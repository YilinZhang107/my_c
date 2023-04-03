#include<bits/stdc++.h>
using namespace std;

int n,m,k,t;
int ocp[505];
int fa[505];
int vis[505];
struct road{
    int a,b;
}roads[5005];

void init(){
    for(int i=0;i<n;i++){fa[i] = i;}
}
int  find(int v){
    while(fa[v] != v ){
        v = fa[v];
    }
    return v;
}
void uni(int a,int b){ //注意它的写法
    a = find(a);
    b = find(b);
    if(a==b)
        return;
    else
        fa[a] = b;//
  
}
int fcnt(){//求连通分量
    int cnt=0;
    for(int i=0;i<n;i++){
        if(ocp[i] != 1 && fa[i] == i) cnt++;
    }
    return cnt;
}
void remake(){
    init();
    for(int i=0;i<m;i++){
        if(ocp[roads[i].a] != 1 && ocp[roads[i].b] != 1){
            uni(roads[i].a, roads[i].b);
        }
    }
}
bool isOver(){
    for(int i=0;i<n;i++){
        if(ocp[i] == 0)
            return false;
    }
    return true;
}
int main(){
    cin>>n>>m;
    int i;
    memset(vis,0,sizeof(vis));
    memset(ocp,0,sizeof(ocp));//是否被占领
    for(i=0;i<m;i++){
        scanf("%d %d",&roads[i].a,&roads[i].b);
    }
    
    remake();
    int cnt = fcnt();
    int now;
    cin>>k;
    while(k--){
        cin>>t;
        ocp[t] = 1;
        remake();
        now = fcnt();
        if(now==cnt || now+1==cnt){
            printf("City %d is lost.\n",t);
            cnt = now;
        }else{
            printf("Red Alert: City %d is lost!\n",t);
            cnt = now;
        }
    }

    if(isOver()){
        cout<<"Game Over."<<endl;
        return 0;
    }
    return 0;
}