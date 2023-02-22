#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    int flag;
    for(int i=0;i<n;i++){
        flag = 1;
        int p = s[i].find("P");
        if(p == -1){
            cout<<"NO"<<endl;
            continue;
        }
        string before = s[i].substr(0,p);
        for(char c: before){//判断P之前的子字符串
            if(c!= 'A'){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
            continue;
        }
        string a = before;
        before = s[i].substr(p+1);
        if(before[0] != 'A'){
            cout<<"NO"<<endl;
            continue;
        }
        for(int j=0; j<before.size(); j++){
            if(before[j] == 'T'){
                before = before.substr(j+1);
                break;
            }
            else if(before[j] != 'A'){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
            continue;
        }
        for(char c: before){//判断P之前的子字符串
            if(c!= 'A'){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }


    return 0;
}