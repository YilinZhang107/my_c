#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

void Msort(int &a,int &b,int &c){
    if(a>b)
        swap(a,b);
    if(b>c)
        swap(b,c);
    if(a>b)
        swap(a,b);
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    Msort(a,b,c);
    cout<<a<<' '<<b<<' '<<c;
    return 0;
}
