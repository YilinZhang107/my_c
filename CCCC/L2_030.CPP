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
//不知道哪错了14分

//int fa[100005];
unordered_map<string, string> xu;

//void uni()
unordered_map<string,int> xin;
void mfind(string s){
	
}

int main(){
    cin>>n;
    string a,b;
//    _for(i,0,n){
//    	fa[i] = i;
//	}
	_for(i,0,n){
		cin>>a>>b;
		if(b.find("sson") != string::npos){
			xu[a] = b.substr(0,b.size()-4);
			xin[a] = 1;
//			bug(xu[a]);
		}else if(b.find("sdottir") != string::npos){
			xu[a] = b.substr(0,b.size()-7);
			xin[a] = 0;
//			bug(xu[a]);
		}else{
			xu[a] = a;
			xin[a] = 1;
//			bug(xu[a]);
		}
	}
	cin>>m;
	string c,d;
	_for(i,0,m){
		cin>>a>>b>>c>>d;
		if(!xu.count(a) || !xu.count(c)) {
			cout<<"NA"<<endl;
		}else if(xin[a] == xin[c]){
			cout<<"Whatever"<<endl;
		}else{
			set<string> zx;
			int dai = 1;
			while(xu[a] != a && dai<5){
				zx.insert(a);
				a = xu[a];
				dai++;
			}
			if(dai != 5)
				zx.insert(a);
			dai = 1;
			int f =1;
			while(xu[c] != c && dai<5){
				if(zx.count(c)){
					f =0;
					break;
				}
				c = xu[c];
				dai++;
			}
			if(dai != 5){
				if(zx.count(c))
					f =0;
			}
		
			if(f) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}

    return 0;
}