#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double lilv;
    vector<int> v;
    cin>>n>>lilv;
    for(int i=0; i<=n; i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    double sum =1.0 * v[0];
    for(int i=1; i<=n; i++){
        sum += v[i]*pow(1+lilv, -1*i);
    }
    cout<<sum;
    return 0;
}