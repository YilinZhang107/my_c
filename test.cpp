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
    
    string  s= "1 and is the 2";
    // s.erase(5,1);
    // bug(s);
    // s.replace(5,1,"XXX");
    // bug(s);
    vi v = {1,2,3,1,2,4,1,23,87,12,3,23};
    sort(v.begin(),v.end());
    rep(i,0,v.size()-1) cout<<v[i]<<" ";
    cout<<endl;
    v.insert(v.begin()+2, 10);
    rep(i,0,v.size()-1) cout<<v[i]<<" ";

    return 0;
}