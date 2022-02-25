#include<bits/stdc++.h>
using namespace std;

int main(){
    int year,month;
    bool run;
    cin >>year>>month;
    if((year%4==0&&year%100!=0)||(year%400==0))
        run = 1;
    else
        run = 0;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        cout<<"31";
    else if(month==2){
        if(run)
            cout<<"29";
        else
            cout<<"28";
    }
    else
        cout<<"30";
    return 0;
}