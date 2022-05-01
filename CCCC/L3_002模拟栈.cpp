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


int main(){
    cin>>n;
    string s;
    getchar();
    vi ans;
    stack<int> my;
    int mid;
    _for(i,0,n){
    	getline(cin,s);
    	if(s.find("Push") != string::npos){
    		int pos =  s.find(" ");
//    		bug(pos);
    		int in = stol(s.substr(pos,s.size()-pos));
//    		bug(in);
			my.push(in);
			auto it  = lower_bound(ans.begin(), ans.end(),in);

			if( it != ans.end()){
				ans.insert(it, in);
//				_for(j,0,ans.size()) cout<<ans[j]<<endl;
			}else{
				ans.pb(in);
//				_for(j,0,ans.size()) cout<<ans[j]<<endl;
			}
		}else if(s.find("Pop")!= string::npos && s.size()==3 && ans.size()!=0){
			cout<<my.top()<<endl;
			auto it = find(ans.begin(),ans.end(),my.top());
			ans.erase(it);
			my.pop();
		}else if(s.find("PeekMedian") !=string::npos && s.size()==10 && ans.size()!=0){
			if(ans.size() & 1){
				cout<<ans[(ans.size()+1)/2-1]<<endl;
			}else{
				cout<<ans[ans.size()/2-1]<<endl;
			}
		}else{
			cout<<"Invalid"<<endl;
		}
	}

    return 0;
}