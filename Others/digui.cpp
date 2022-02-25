#include<bits/stdc++.h>
using namespace std;

long long fei(long long n){
    if(n == 1 || n==2){
        return 1;
    }
    return fei(n-1)+fei(n-2);
}

int main(){
    for(int i=1;i<=30;i++){
        cout<<fei(i)<<' ';
    }
}
