#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 99999999
int n,m,k;

struct node{
	int num;
	vi out;
};
map<vector<int>,int > mp;
vector<node> ans;
bool cmp(node a,node b){
	if(a.num == b.num){
		return a.out<b.out;
	}else{
		return a.num>b.num;
	}
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t;
		vi now;
		for(int j=0;j<m;j++){
			cin>>t;
			now.push_back(t);
		}
		if(mp.count(now)){
			mp[now]++;
		}else{
			mp[now]  = 1;
		}
	}
	for(auto i: mp){
		node ne;
		ne.num = i.second;
		ne.out = i.first;
		ans.push_back(ne);
	}
	sort(ans.begin(), ans.end(),cmp);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].num;
		for(int j=0;j<m;j++){
			cout<<" "<<ans[i].out[j];
		}
		cout<<endl;
	}
    return 0;
}