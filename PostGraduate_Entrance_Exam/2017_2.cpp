#include<bits/stdc++.h>
using namespace std;

string same(string str){
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}

int main(){
    string s;
    vector<string> strs;
    cin>>s;
    int diff,n;
    cin>>diff>>n;
    for(int i=0; i<n; i++){
        string t;
        cin>>t;
        strs.push_back(t);
    }
    
    if(diff == 1){//敏感
        for(int i=0;i<n;i++){
            if(strs[i].find(s) != -1)
                cout<<strs[i]<<endl;
        }
    }
    else{//not diff
        s = same(s);
        for(int i=0; i<n;i++){
            if(same(strs[i]).find(s) != -1)
                cout<<strs[i]<<endl;
        }
    }
    return 0;
}