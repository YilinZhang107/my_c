#include<bits/stdc++.h>
using namespace std;


int main(){
    ifstream infile;
    infile.open("D://text.txt",ios::in);
    int t;
    int a[87575];
    int b[87575];
    int c[87575];
    for(int i=0; i<87575; i++){
        infile>>t;
        a[i] = t;
        infile>>t;
        b[i] = t;
        infile>>t;
        c[i] = t;
    }
    int d[175150];
    //cout<<a[1]<<b[1]<<c[1]<<endl;
    //int d[121961];
    int e[121961];
    for(int i=0; i<121961; i++){
        //infile>>t;
        //d[i] = t;
        infile>>t;
        e[i] = t;
    }
    //cout<<d[0]<<e[0]<<endl;
    //cout<<d[121960]<<e[121960]<<endl;
    return 0;
}