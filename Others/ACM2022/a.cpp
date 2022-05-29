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
    int a,b,c;
    cin>>a>>b>>c;
    bool ans = false;
    int sum = a*a + b*b;
    int n = sqrt(sum);
    // bug(sum);
    a = abs(a);
    b = abs(b);
    for(int i=0; i<=n ;i++){
        for(int j=i; j<=n; j++){
            if(i*i + j*j == sum){
                // bug(i);
                // bug(j);
                // int t = i^j;
                // bug(t);
                if( (i^j) == c){
                    ans = true;
                    break;
                }
                
                
            }
        }
        if(ans) break;
    }

    if(ans) cout<<"YES";
    else cout<<"NO";

    return 0;
}