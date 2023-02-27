#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n; i++){
        vector<int> vt;
        int t;
        for(int j=0; j<n;j++){
            cin>>t;
            vt.push_back(t);
        }
        v.push_back(vt);
    }
    multiset<int,greater<int>> s;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += v[i][j];
        }
        s.insert(sum);
    }
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += v[j][i];
        }
        s.insert(sum);
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += v[i][i];
    }
    s.insert(sum);
    sum=0;
    for(int i=0,j=n-1; i<n; i++,j--){
        sum += v[i][j];
    }
    s.insert(sum);
    
    for(auto i=s.begin(); i!=s.end(); i++)
        cout<<*i<<" ";
    return 0;
}