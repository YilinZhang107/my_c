#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;

string str[1005];
int zw[1005];

int main(){
    cin>>n;
    string s;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        str[a] = s;
        zw[a] = b;
    }
    cin>>n;
    while(n--){
        cin>>k;
        cout<<str[k]<<" "<<zw[k]<<endl;
    }
    return 0;
}