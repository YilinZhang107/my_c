#include<bits/stdc++.h>
using namespace std;

vector<string> xings;
vector<string> mings;
vector<string> ans;

void check(string& n1, string&x1, string& n2, string& x2){
    int find1 = -1, find2=-1, s1=-1, s2=-1; // 0 女, 1男
    for(int i=0; i<mings.size(); i++){
        if(mings[i] == n1){
            if(xings[i] == x1+"sson"){
                s1 = 1;
                find1 = i;
            }
            else if(xings[i] == x1+"sdottir"){
                s1 = 0;
                find1 = i;
            }
        }
        else if(mings[i] == n2){
            if(xings[i] == x2+"sson"){
                s2 = 1;
                find2 = i;
            }
            else if(xings[i] == x2+"sdottir"){
                s2 = 0;
                find2 = i;
            }
        }
    }
    if(find1==-1 || find2 == -1){
        ans.push_back("NA");
        return;
    }
    if(s1 == s2){
        ans.push_back("Whatever")
        return ;
    }
    set<string> pub;
    int dai = 1;
    while(dai++ <5){
        if(pub.count(x1) || pub.count(x2)){
            ans.push_back("NO");
            return 0;
        }
        for(int )
        pub.insert()

    }
        
}

int main(){
    int n;
    cin>>n;
    string xing, ming;
    for(int i=0; i<n; i++){
        cin>>ming>>xing;   
        mings.push_back(ming);
        xings.push_back(xing);
    }

    // int m;
    cin>>n;
    getchar();
    string n1, n2, x1,x2;
    for(int i=0; i<n; i++){
        cin>>n1>>x1>>n2>>x2;

    }
    
    return 0;
}