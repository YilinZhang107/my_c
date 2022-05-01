#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;


int main(){
    char c;
    double a;
    cin>>a>>c;
    for(int i=0;i<int(a/2.0+0.5); i++){
        for(int j=0;j<(int)a;j++){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}