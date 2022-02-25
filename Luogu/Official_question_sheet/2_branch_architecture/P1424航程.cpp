#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    int sum=0;
    if(6-x>0)//减去第一周
        sum = sum+250*(6-x);
    n = n - (8-x);

    //中间日子
    sum = sum + n/7*5*250;

    //最后一周
    n = n%7;
    if(n>5)
        sum = sum+ 250*5;
    else
        sum = sum + 250*n;
    
    cout<<sum;
    return 0;

        
}