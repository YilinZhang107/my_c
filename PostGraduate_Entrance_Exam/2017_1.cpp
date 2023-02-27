#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n; i++){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int little=0, big=0, mid = v.size()/2;
    for(int i=mid-1; i>=0; i--){
        if(v[i] != v[mid])
            little++;
    }
    for(int i=mid+1; i<v.size(); i++){
        if(v[i] != v[mid])
            big++;
    }
    if(little == big)
        cout<<v[mid];
    else 
        cout<<-1;
    return 0;
}