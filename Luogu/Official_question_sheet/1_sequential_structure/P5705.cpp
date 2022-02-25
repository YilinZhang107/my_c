#include<iostream>
using namespace std;
 
int main(){
    double d;
    cin >> d;
    cout << int(d*10)%10 << "." << int(d)%10 << int(d)/10%10 << int(d)/100;
    return 0;
}