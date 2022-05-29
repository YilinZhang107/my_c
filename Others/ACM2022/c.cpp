#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 99999999
#define INF 0x3f
#define ll long long
#define endl '\n'
#define _for(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a; i<=b;i++)
#define bug(a)  cout<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
int n,m,k;

const ll mod = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int a,b;
    ll ans=0;
    rep(i,1,n){
        cin>>a>>b;
        int t = b-a+1;
        rep(j,a,b){
            int t1 = t*n;
            // bug(t1);
            ans = (ans+ j*mod/(t*n))%mod;
        }

    }
    cout<<ans;
    return 0;
}