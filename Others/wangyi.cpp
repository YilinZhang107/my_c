#include<bits/stdc++.h>
using namespace std;

int tran(string n,int z){
    int sum = 0;
    int x= 1;
    for(int i=n.size()-1; i>=0; i--){
        sum += (n[i]-48)*x;
        x = x*z;
    }
    return sum;
}

int main(){
    string str;
    int x,y;
    cin>>str;
    cin>>x>>y;

    int p1=1,p2=1;
    string str1 = str.substr(0,p1++) ,str2 = str.substr(str.size()-p2,p2) ;
    p2++;
    
    for(int i=0; i<str.size(); i++){
        int answer = tran(str1,x)-tran(str2,y);
        
        if(answer==0 && (p1+p2-2)==str.size()){
            cout<<tran(str1,x);
            return 0;
        }
        else if(answer<=0){
            str1 = str.substr(0,p1++);
        }
        else if(answer>0){
            str2 = str.substr(str.size()-p2,p2);
            p2++;
        }
    }
    return 0;
}