#include<bits/stdc++.h>
using namespace std;

bool isZhi(int x){
    if(x<2)
        return false;
    // 小于根号x即可
    for(int i=2; i<=sqrt(x); i++){
        if (x%i == 0)
            return false;
    }
    return true;
}

int main(){
    int n, t;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin>>t;
        if(isZhi(t))
            v.push_back(t);
    }
    for(int i=0; i<v.size(); i++){
        if(i==0){
            cout<< v[0];
        }
        else
            cout<<" "<<v[i];
    }

    return 0;
}


