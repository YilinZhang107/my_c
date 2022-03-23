#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    char c;
    cin>>num>>c;
    int line =1, used = 1;
    while((used + (line+2)*2) < num){
        line+=2;
        used += line*2;
    }
    for(int i=line; i>=1; i-=2){
        //输出空格
        for(int j=i; j<line; j+=2)
            cout<<" ";
        for(int j=0; j<i; j++)
               cout<<c;
        cout<<endl;
    }
    for(int i=3; i<=line; i+=2){
        //输出空格
        for(int j=i; j<line; j+=2)
            cout<<" ";
        for(int j=0; j<i; j++)
               cout<<c;
        cout<<endl;
    }
    cout<< num-used<<endl;   
    return 0;
}