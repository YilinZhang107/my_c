#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a;
    cin>>a;
    int i;
    for(i=1; i>0; i++){
        if(a==1)
            break;
        else
            a /= 2;
    }
    cout<<i;
    return 0;
}