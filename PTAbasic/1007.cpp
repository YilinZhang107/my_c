#include<bits/stdc++.h>
using namespace std;

bool issu(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=2; i<=n; i++){
        if(issu(i)){
            v.push_back(i);
        }
    }
    int ans=0;
    for(int i=1; i<v.size();i++){
        if(v[i]-v[i-1] == 2)
            ans++;
    }
    cout<<ans;
    return 0;
}