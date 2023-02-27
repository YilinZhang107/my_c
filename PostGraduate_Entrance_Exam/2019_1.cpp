#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,now, last=0,sum = 0, score = 2;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>now;
        if(now ==1){
            sum += 1;
            if(last == 2){
                score = 2;
            }
            last = now;
        }
        else if(now == 2){
            if(last == 2){
                score *= 2;
                sum += score;
            }
            else{
                last  = now;
                sum += score;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}

