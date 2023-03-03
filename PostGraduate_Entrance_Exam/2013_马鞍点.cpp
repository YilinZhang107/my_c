#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n,has = 0;
    cin>>m>>n;
    vector<vector<int>> v;
    vector<int> mmin;
    for(int i=0;i <m; i++){
        vector<int> t;
        int temp,min = INT_MAX;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp<min)
                min = temp;
            t.push_back(temp);
        }
        v.push_back(t);
        mmin.push_back(min);
    }
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            if(v[i][j] != mmin[i])
                continue;
            int flag = 1;
            for(int l=0; l<m; l++){
                if(v[l][j] > v[i][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout<<i<<" "<<j<<" "<<v[i][j]<<endl;
                has = 1;
            }
        }
    }
    if(!has)
        cout<<"no"<<endl;
    return 0;
}