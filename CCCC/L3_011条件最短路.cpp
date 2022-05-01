#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 99999999
#define INF 0x3f
#define endl '\n'
#define _for(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a; i<=b;i++)
#define bug(a)  cout<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
int n,m,k;

int e[205][205], vis[205],dis[205],pre[205],zb[205],cnt[205];
int sum[205],rootCnt[205];
map<string,int> cheng;

void dij(int s,int d){
	memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    dis[s] = 0;
	cnt[s] = 0;//解放数量 
	sum[s] = 0;//杀敌 
	rootCnt[s] = 1;
	rep(i,0,n){
		int v = -1;
		rep(j,0,n){
			if(!vis[j] && (v==-1 || dis[j]<dis[v]))
				v = j;
		}
		vis[v] = 1;
		rep(j,0,n){
			if( dis[j] > dis[v]+e[j][v]){
				dis[j] = dis[v] +e[j][v];
				cnt[j] = cnt[v]+1;
				sum[j] = sum[v]+zb[j];
				pre[j] = v;
				rootCnt[j] = rootCnt[v];
			}else if(dis[j] == dis[v]+e[j][v]){
				rootCnt[j]+=rootCnt[v];
				if(cnt[j] < cnt[v]+1){
					cnt[j] = cnt[v]+1;
					pre[j] = v;
					sum[j] = sum[v]+zb[j];
				}else if(cnt[j]==cnt[v]+1){
					if(sum[j] < sum[v] + zb[j]){
						pre[j] = v;
						sum[j] = sum[v]+zb[j];
					}
				}
			}
		}
	}
}

int main(){
    string my,ene,a,b;
    int d,ad;
	cin>>n>>k>>my>>ene;
	memset(e,INF,sizeof(e));
	cheng[my] = 0;
	_for(i,1,n){
		cin>>a>>d;
		cheng[a] = i;
		zb[i] = d;
	}
	rep(i,1,k){
		cin>>a>>b>>d;
        // bug(cheng[a]);
        // bug(cheng[b]);
		e[cheng[a]][cheng[b]] = d;
		e[cheng[b]][cheng[a]] = d;
       
 	}
 	d = cheng[ene];
 	dij(0,d);
    ad = d;
    stack<int> ans;
    while(d != 0){
    	ans.push(d);
    	d = pre[d];
	}
	
	vi ians;
	while(!ans.empty()){
		ians.pb(ans.top());
		ans.pop();
	}
    
	cout<<my;
	_for(i,0,ians.size()){
		for(auto it=cheng.begin(); it!=cheng.end();it++){
			if(it->second == ians[i]){
				cout<<"->"<<it->first;
				break;
			}
		}
	}
	cout<<endl;
	cout<<rootCnt[ad]<<" "<<dis[ad]<<" "<<sum[ad];

    return 0;
}