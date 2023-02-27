#include<bits/stdc++.h>
using namespace std;

bool isNum(char c){
    if(c>='0' && c<='9')
        return 1;
    else 
        return 0;
}


int main(){
    string zip,s="";
    cin>>zip;
    char c;
    for(int i=0; i<zip.size(); i++){
        if(i != zip.size()-1 && isNum(zip[i+1]) ){ //后面有数字
            int len=1;
            while(isNum(zip[i+len+1]))
                len++;
            string n = zip.substr(i+1,len);
            int sum = 0,cheng = 1;
            for(int j=n.size()-1; j>=0; j--){
                sum += (n[j]-'0')*cheng;
                cheng *= 10;
            }
            for(int j=0; j<sum; j++)
                s += zip[i];
            i += len;
        }
        else
            s += zip[i];
    }
    cout<<s<<endl;
    return 0;
}