#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int yu[n],see[n]={0};
    for(int i=0; i<n; i++){
        cin>>yu[i];
        for(int j=0; j<i; j++){
            if(yu[j]<yu[i])
                see[i]++;
        }
    }
    for(int i=0; i<n; i++)
        cout<<see[i]<<" ";
    return 0;
}