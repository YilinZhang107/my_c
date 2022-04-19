#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,num;
    cin>>n1>>n2>>num;
    vector<int> v;
    v.push_back(n1);
    v.push_back(n2);
    int i=0;
    while(v.size()< num){
        long long t = v[i]*v[i+1];
        if(t>9){
            string s = to_string(t);
            for(char c: s){
                v.push_back(c-'0');
            }
        }
        else
            v.push_back(t);
        i++;
    }
    for(i=0; i<num; i++){
        if(i==0)
            cout<<v[i];
        else
            cout<<' '<<v[i];
    }

    return 0;

}