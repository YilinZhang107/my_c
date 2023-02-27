#include<bits/stdc++.h>
using namespace std; //水仙花数

int main(){
    int n,sum=0,t;
    cin>>n;
    t = n;
    for(int i=0;i<3;i++){
        int temp = t%10;
        t /= 10; 
        sum += temp*temp*temp;
    }
    if(sum == n)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}