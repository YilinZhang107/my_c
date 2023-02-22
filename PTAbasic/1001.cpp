#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    int ans  = 0;
    while(n != 1){
        if(n%2){
            n = (n*3+1)/2;
        }
        else
            n= n/2;
        ans++;
    }
    cout<<ans;
    return 0;
}