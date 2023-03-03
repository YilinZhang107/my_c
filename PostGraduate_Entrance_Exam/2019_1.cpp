#include<bits/stdc++.h> 
using namespace std;

int main(){
    int t,n, sum =0 , max = INT_MIN, min=INT_MAX;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        sum+=t;
        if(t<min)
            min = t;
        if(t>max)
            max = t;
    }
    cout<<sum<<" "<<min<<" "<<max<<endl;
    return 0;
}