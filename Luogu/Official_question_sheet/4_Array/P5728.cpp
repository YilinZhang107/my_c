#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=0;
    int yu[1001]={},shu[1001]={},ying[1001]={};
    for(int i=0; i<n; i++){
        cin>>yu[i]>>shu[i]>>ying[i];
        for(int j=0; j<i; j++){
            if(abs(yu[j]-yu[i])<=5 && abs(shu[j]-shu[i])<=5 && abs(ying[j]-ying[i])<=5 && abs((shu[j]+yu[j]+ying[j])-(yu[i]+shu[i]+ying[i]))<=10)
                sum++;
        }       
    }
    cout<<sum;
    return 0;
}