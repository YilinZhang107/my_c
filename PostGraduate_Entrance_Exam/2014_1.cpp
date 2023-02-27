#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>t;
        if(mp.count(t))
            mp[t]++;
        else
            mp[t] = 1;
    }
    int maxn = 0,ans;
    for(auto i=mp.begin(); i!=mp.end(); i++){
        // cout<<(*i).first<<" "<<(*i).second<<endl;
        if(i->second>maxn){
            ans = i->first;
            maxn = i->second;
        }
    }
    cout<<ans;
    return 0;
}