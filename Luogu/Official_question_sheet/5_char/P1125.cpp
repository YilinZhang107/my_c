#include<bits/stdc++.h>
using namespace std;

int isZhi(int n){
    int is = 1;
    
    if(n<2)
        return 0;

    int nf = (int)sqrt(n+0.0);
    for(int i=2; i<=nf; i++){
        if(n%i==0)
            is = 0;
    }
    return is;
}

int main(){
    string str;
    cin>>str;

    int ascii[26] = {0};

    for(int i=0; i<str.size(); i++){
        //int number = str[i];
        ascii[str[i]-97]++;
    }

    int max=0;
    int min=100;
    for(int i=0; i<26; i++){
        if(ascii[i] != 0 && ascii[i]>max)
            max = ascii[i];
        if(ascii[i] != 0 && ascii[i]<min)
            min = ascii[i];
    }

    if(isZhi(max-min)){
        cout<<"Lucky Word"<<endl;
        cout<<max-min;
    }else{
        cout<<"No Answer"<<endl;
        cout<<"0";
    }
    return 0;
}