#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int min, input;
    for(int i =0;i<n;i++){
        cin>>input;
        if(i==0)
            min = input;
        else{
            min = input<min ? input:min;
        }
    }
    cout<<min;
    return 0;
}