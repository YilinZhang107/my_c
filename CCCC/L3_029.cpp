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

int yuan[100005];
vi in[1005];
vi ans;
int vis[1005];
int main(){
    cin>>n;
    rep(i,1,n){
    	scanf("%d",&yuan[i]);
	}
	cin>>m;
	rep(i,1,m){
		int t;
		cin>>k;
		while(k--){
			cin>>t;
			in[i].pb(t);
		}
	}
	int pos =1;
	int sx =1;
	while(pos < n){
	//	bug(pos);
		rep(i,1,m){
			int flag = 1;
			if(!vis[i] && in[i][0] == yuan[pos]){
				//bug(i);
			//	bug(in[i][0]);
				
				_for(j,1,in[i].size()){
					if(in[i][j] != yuan[pos+j]) {
						flag = 0;
						break;
					}
				}
				if(flag){
					pos+=in[i].size()-1;
					vis[i] = 1;
					//bug(sx);
					ans.pb(i);
					
					break;
				}
			}
		}
	}
	rep(i,0,m-1){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}

    return 0;
}