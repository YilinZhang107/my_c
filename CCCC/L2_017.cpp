#include<bits/stdc++.h>
using namespace std;
int n,m,k;

int sumh=0,suml=0;
int v[100005];

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        scanf("%d", &v[i]);
    }
    sort(v,v+n);
    bool gao = 0;
    if(n&1){
        for(int i=0;i<n/2;i++) suml+=v[i];
        for(int i=n/2;i<n;i++) sumh+=v[i];
        cout<<"Outgoing #: "<<n/2+1<<endl;
        cout<<"Introverted #: "<<n/2<<endl;
        cout<<"Diff = "<<sumh-suml;

    }else{
        for(int i=0;i<n/2;i++) suml+=v[i];
        for(int i=n/2;i<n;i++) sumh+=v[i];
        cout<<"Outgoing #: "<<n/2<<endl;
        cout<<"Introverted #: "<<n/2<<endl;
        cout<<"Diff = "<<sumh-suml;
    }

    return 0;
}