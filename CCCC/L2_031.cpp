#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int origin[100005] = {0};
//可以dfs也可以bfs, bfs很妙,直接输出队列中最后的数字就是最深的
void bfs(int start){
	queue<int> q;
	q.push(start);
	int ans = start;

	while(!q.empty()){
		for(int t: v[q.front()-1]){
			q.push(t);
		}
		ans = q.front();
		q.pop();
	}
	cout<<ans;
	return;
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		vector<int> temp;
		while(k--){
			int t;
			cin>>t;
			temp.push_back(t);			
			origin[t] = 1;
		}
		v.push_back(temp);
	}
	
	for(int i=1; i<=n; i++){
		if(!origin[i])
			bfs(i);
	}
	
	return 0;
	
}