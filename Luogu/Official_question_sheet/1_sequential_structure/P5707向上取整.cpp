#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,v;
    cin>>s>>v;

    int time = ceil(s/v)+10;  //直接向上取整
    /*
    int time = s/v;
    if(s%v!=0)      
        time++;
    time += 10;
    */

    int hour, min;
    hour = time/60;
    min = time%60;
    if(hour<8){
        if(min!=0){
            cout<<'0'<<7-hour<<':';
            if(60-min>=10)
                cout<<60-min;
            else
                cout<<'0'<<60-min;       
        }
        else
            cout<<'0'<<8-hour<<':'<<"00";
    }
    else{
        if(min!=0)
            if(31-hour>=10){
                cout<<23-(hour-8)<<':';
                if(60-min>=10)
                    cout<<60-min;
                else
                    cout<<'0'<<60-min;
            }
            else{
                cout<<'0'<<23-(hour-8)<<':';
                if(60-min>=10)
                    cout<<60-min;
                else
                    cout<<'0'<<60-min;
            }       
        else
            if(32-hour>=10)
                cout<<24-(hour-8)<<':'<<"00";
            else
                cout<<'0'<<24-(hour-8)<<':'<<"00";
    }
    return 0;
}
