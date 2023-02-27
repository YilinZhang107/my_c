#include<bits/stdc++.h>
using namespace std;

int divideSum(int n){
    int sum = 0;
    while(n!=0){  
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    set<int> s;
    int t;
    cin>>t;
    while(t != 0){
        s.insert(divideSum(t));
        cin>>t;
    }
    for(auto i=s.begin() ; i!=s.end(); i++)
        cout<<*i<<" ";
    return 0;

}