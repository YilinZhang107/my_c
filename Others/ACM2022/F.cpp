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

int t[100005];
map<int ,int > A;
map<int ,int > C;
vi v;

int max3(int a,int b,int c){
    if(a>b) b = a;
    return max(b,c);
}
int min3(int a,int b,int c){
    if(a<b) b = a;
    return min(b,c);
}
int cal(int a,int b, int c){
    return max3(a,b,c)-min3(a,b,c);
}

int main(){
    ios::sync_with_stdio(false);
    cin>>k;
    while(k--){
        memset(t,0,sizeof(t));
        A.clear();
        C.clear();
        // s.clear();
        v.clear();
        cin>>n;
        int T;
        _for(i,0,n){
            cin>>T;
            t[i] = T;
            // s.insert(t[i]);
        }
        sort(t,t+n);
        int now = t[0];
        _for(i,1,n){
            if(now != t[i]){
                v.push_back(now);
                // bug(i);
                A[now] = i;
                C[now] = n-i;
                now = t[i];
            }
        }
        A[t[n-1]] = n;
        C[t[n-1]] = 0;
        v.push_back(t[n-1]);

        int ans = MAX;
        _for(i,0,v.size()){
            _for(j, i+1, v.size()){
                int ta = A[v[i]];
                int tc = C[v[j]];
                // bug(ta);
                // bug(tc);
                T = cal(ta,n-ta-tc,tc);
                cout<<"T: "<<T<<" i: "<<i<<" j: "<<j<<endl;
                if(T< ans) ans = T;
            }
        }
        if(v.size()==1) ans = n;
        cout<<ans<<endl;
    }

    return 0;
}