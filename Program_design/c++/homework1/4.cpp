#include<bits/stdc++.h>
using namespace std;

template <class T> void Msort(T a,T b){
    if(a>b){
        T t = a;
        a = b;
        b = t;
    }
    cout<<a<<' '<<b<<endl;
}

int main(){
    int a=10,b=5;
    double c=2.5, d=1.5;
    Msort(a,b);
    Msort(c,d);
    return 0;
}