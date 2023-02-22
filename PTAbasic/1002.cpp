#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin>>n;
    vector<string> s = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    int ans = 0;
    for(int i=0; i<n.size(); i++){
        ans += n[i]-48;
    }
    stack<string> strs;
    while(ans != 0){
        strs.push(s[ans%10]);
        ans /= 10;
    }
    int first = 1;
    while(!strs.empty()){
        if(!first)
            cout<<" ";
        cout<<strs.top();
        first = 0;
        strs.pop();
    }
    return 0;
}