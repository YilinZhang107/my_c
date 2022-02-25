#include<bits/stdc++.h>
using namespace std;

int main(){
    char num[10];
    cin>>num;
    int length = 0;

    while(num[length] != '\0')
        length++;

    if(length ==1 && num[0]=='0'){
        cout<<'0';
        return 0;
    }
    //是不是正数
    int sum = 1;
    if(num[0]=='-'){
        sum = 0;
        //length-=1;
    }

    //头部是否是0
    int head = 0;

    if(sum==0){
        cout<<'-';
        for(int i=length-1; i>0; i--){
            if(head==0 && num[i]=='0'){
                continue;
            }else{
                head = 1;
                cout<<num[i];
            }
        }
    }

    if(sum==1){
        for(int i=length-1; i>=0; i--){
            if(head==0 && num[i]=='0'){
                continue;
            }else{
                head=1;
                cout<<num[i];
            }
        }
    }
    return 0;
}