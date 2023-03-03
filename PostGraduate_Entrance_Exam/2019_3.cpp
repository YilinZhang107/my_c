#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,max=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0 ; j<n-i; j++)
            cout<<" ";
        for(int j=0 ; j<2*i-1; j++)
            cout<<"*";
        for(int j=0 ; j<n-i; j++)
            cout<<" ";
        cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        for(int j=0 ; j<n-i; j++)
            cout<<" ";
        for(int j=0 ; j<2*i-1; j++)
            cout<<"*";
        for(int j=0 ; j<n-i; j++)
            cout<<" ";
        cout<<endl;
    }
    return 0;
}