#include<bits/stdc++.h>
using namespace std;

int main(){
    int A[3];
    cin>>A[0]>>A[1]>>A[2];
    sort(A,A+3);
    int a=A[0], b=A[1], c=A[2];
    if(a+b>c){
        if(a*a+b*b>c*c)
            cout<<"Acute triangle"<<endl;
        else if(a*a+b*b==c*c)
            cout<<"Right triangle"<<endl;
        else
            cout<<"Obtuse triangle"<<endl;
        if(a==b)
            cout<<"Isosceles triangle"<<endl;
        if(a==c)
            cout<<"Equilateral triangle"<<endl;
    }
    else{
        cout<<"Not triangle";
    }
    return 0;
}