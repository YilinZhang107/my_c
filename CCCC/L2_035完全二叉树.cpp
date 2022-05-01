#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;

//巨牛这个

int tree[36];
void dfs(int v){
	if(v>n) return ;
	dfs(v*2);
	dfs(v*2+1);
	cin>>tree[v];
}

int main(){
	cin>>n;
	dfs(1);
	for(int i=1;i<=n;i++){
		if(i!=1) cout<<" ";
		cout<<tree[i];
		
	}
	
	
    return 0;
}