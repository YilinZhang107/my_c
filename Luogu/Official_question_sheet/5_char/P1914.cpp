#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n>=26)
        n = n%26;

    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++){
        str[i] -= 26;  //防止越界ascii码只有128位

        str[i] += n;
        if(str[i]>122-26)
            str[i]-=26;
        
        str[i]+=26;
    }
    cout<<str;
    return 0;
}