#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;


int ans[10];
int main(){
    string s;
    cin>>s;
    memset(ans,0,sizeof(ans));
    for(int i=0;i<s.size();i++){
        ans[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(ans[i] != 0)
            cout<<i<<":"<<ans[i]<<endl;
    }
    return 0;
}