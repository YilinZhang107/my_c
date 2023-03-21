#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, yan[105] = {0};
    cin>>n;
    vector<int> v;
    set<int, greater<int>> s;
    while(n--){
        int t;
        cin>>t;
        v.push_back(t);
        yan[t] = 1;
    }
    for(int i=0; i<v.size(); i++){
        n = v[i];
        while(n != 1){
            if(n%2){
                n = (n*3+1)/2;
            }
            else
                n= n/2;
            if(n<101)
                yan[n] = 0; 
        }
    }
    for(int i=0;i<105; i++){
        if(yan[i])
            s.insert(i);
    }
    for(auto j = s.begin(); j!= s.end(); j++){
        if(j!=s.begin())
            cout<<" ";
        cout<<*j;
    }
    return 0;
}