#include<bits/stdc++.h>
using namespace std;

int main(){
    int num[100];
    int i;
    for(i=0; i<100; i++){
        cin>>num[i];
        if(num[i]==0)
            break;
    }
    i--;
    for(;i>=0;i--)
        cout<<num[i]<<" ";

    return 0;
}