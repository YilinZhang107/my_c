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
//差2
vi e[505];
int ans = 0,flag = 1;
void dfs(int s,int d){
	if(s==d){
		ans++;
		return;
	}else if(e[s].size() == 0){
		flag=0;
		return ;
	}
	_for(i,0,e[s].size()){
		bug(e[s][i]);
		dfs(e[s][i], d);
	}
}

int main(){
    cin>>n>>m;
    rep(i,1,m){
    	int a,b;
    	cin>>a>>b;
    	e[a].pb(b);
	}
	int s,d;
	cin>>s>>d;
	dfs(s,d);
	cout<<ans<<" ";
	if(flag)	cout<<"Yes";
	else cout<<"No";

    return 0;
}