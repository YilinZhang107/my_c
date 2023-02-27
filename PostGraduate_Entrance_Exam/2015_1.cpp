#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<bool> ans;
    int n,t;
    
    cin>>n;
    while(n!=0){
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>t; 
            v.push_back(t);
        }
        bool yes=1;
        sort(v.begin(), v.end());
        if(v.size() < 3)
            ans.push_back(1);
        else{
            for(int i=0; i<v.size()-2; i++){
                if(v[i+2]-v[i+1] != v[i+1]-v[i]){
                    yes = 0;
                    break;
                }
            }
            ans.push_back(yes);
        }
        cin>>n;
    }
    for(int i=0; i<ans.size(); i++){
        if(ans[i]== 1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}   