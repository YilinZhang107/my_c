#include<bits/stdc++.h>
using namespace std;

int divideSum(int n){
    int sum = 0;
    while(n!= 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

bool isZhi(int n){
    for(int i=sqrt(n); i>1; i--){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    while(n!=0){
        int zhiSum = 0, nSum = divideSum(n);
        vector<int> zhi;
        while(!isZhi(n)){
            for(int i=2; i<=n/2; i++){
                if(!isZhi(i))
                    continue;
                if(n%i==0){
                    zhi.push_back(i);
                    n /= i;
                    break;
                }
            }
        }
        zhi.push_back(n);
        for(int i=0; i<zhi.size(); i++){
            zhiSum += divideSum(zhi[i]);
        }
        if(zhiSum == nSum)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        cin>>n;
    }
    return 0;
}