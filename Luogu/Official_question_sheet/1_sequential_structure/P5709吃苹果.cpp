#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, t, s;
    cin>>m>>t>>s;
    if(t==0){
        cout<<0;
        return 0;
    }
    int aten = s/t;
    if(s%t==0)
        m = m-aten;
    else
        m = m-aten-1;
    if(m>=0)
        cout<<m;
    else
        cout<<0;    
    return 0;
}