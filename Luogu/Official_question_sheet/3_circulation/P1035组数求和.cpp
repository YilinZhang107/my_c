#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    double s=0.0;
    double n=1;  //这里用int也可以
    while(s<=k){
        s = s+1/n;  //这里改为1.0/n就行
        n = n+1;
    }
    cout<<int(n-1);
    return 0;
}