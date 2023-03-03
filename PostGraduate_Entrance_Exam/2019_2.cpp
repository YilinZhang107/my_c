#include<bits/stdc++.h>
using namespace std;

int main(){
    int cheng = 1, er,ans=0;
    cin>>er;
    while(er != 0){
        ans += er%10*cheng;
        cheng *= 2;
        er/=10;
    }
    cout<<ans<<endl;
    return 0;
}