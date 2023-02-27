#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,t,k;
    cin>>n>>m>>t>>k;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> vt;
        int t;
        for(int j=0;j<m;j++){
            cin>>t;
            vt.push_back(t);
        }
        v.push_back(vt);
    }
    vector<int> close(t,0);
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == k){
                if(i!=0 && v[i-1][j] != k)
                    close[v[i-1][j]-1] = 1;
                if(i!=n-1 && v[i+1][j] != k)
                    close[v[i+1][j]-1] = 1;
                if(j!=0 && v[i][j-1] != k)
                    close[v[i][j-1]-1] = 1;
                if(j!=m-1 && v[i][j+1] != k)
                    close[v[i][j+1]-1] = 1;    
            }
        }
    }
    int ans = 0;
    for(int i=0;i<close.size(); i++)
        ans += close[i];
    cout<<ans;
    return 0;
}