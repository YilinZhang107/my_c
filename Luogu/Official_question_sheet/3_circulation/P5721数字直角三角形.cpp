#include<bits/stdc++.h>
using namespace std;
//二维数组
int main(){
    int n;
    cin>>n;
    int chu=1;
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            if(chu<10)
                cout<<"0"<<chu;
            else
                cout<<chu;
            chu++;
        }
        cout<<"\n";
    }
    return 0;
}