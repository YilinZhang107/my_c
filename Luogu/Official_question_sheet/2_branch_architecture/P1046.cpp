#include<bits/stdc++.h>
using namespace std;

int main(){
    int height, pg[10];
    for(int i=0; i<10; i++){
        cin>>pg[i];
    }
    cin>>height;
    int sum=0;
    for(int i=0; i<10; i++){
        if(pg[i]<=height+30)
            sum++;
    }
    cout<<sum;
    return 0;
}