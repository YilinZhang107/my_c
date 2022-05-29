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

int out[1000005];
vi v;
int main(){
    // ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n){
        scanf("%d", &out[i]);
    }
    int ans=0;
    int a,b,f;
    while(m--){
        cin>>f>>a>>b;
        if(f == 1){
            out[a] = b;
        }
        else{//f=2
            ans= 0;
            rep(j,a,b){
                ans += out[j]*(b-j+1);
            }
            v.pb(ans);
        }
    }
    _for(i,0,v.size()) {
        if(i!=0) cout<<endl;
        cout<<v[i];
    }
    return 0;
}