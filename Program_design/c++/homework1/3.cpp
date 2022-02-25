#include<bits/stdc++.h>
using namespace std;

void Msort(int a,int b){
    if(a>b){
        int t = a;
        a = b;
        b = t;
    }
    cout<<a<<' '<<b<<endl;
}

void Msort(double a,double b){
    if(a>b){
        double t = a;
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