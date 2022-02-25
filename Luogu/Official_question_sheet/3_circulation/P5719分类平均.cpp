#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,number=0;
    cin>>n>>k;
    double A=0.0,B=0.0;
    for(int i =1;i<=n;i++){
        if(i%k==0){
            A+=i;
            number++;
        }
        else
            B+=i;
    }
    cout<<setprecision(1)<<fixed<<A/number<<" "<<B/(n-number);
    return 0;
}