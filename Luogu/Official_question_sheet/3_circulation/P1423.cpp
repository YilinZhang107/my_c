#include<bits/stdc++.h>
using namespace std;

int main(){
    double m;
    cin>>m;
    int i = 0;
    double longth = 2.0; //第一天能游2m
    for(i;m>0;i++){
        m -= longth;
        longth *= 0.98;
    }
    cout<<i;
    return 0;
}