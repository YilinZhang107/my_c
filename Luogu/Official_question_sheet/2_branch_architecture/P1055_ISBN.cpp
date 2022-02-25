#include<bits/stdc++.h>
using namespace std;

int main(){
    char isbn[9];
    int num[9];  //其实输入时可以直接用gets(isbn)输入整个字符串
    for(int i =0; i<9; i++){
        cin>>isbn[i];
        if(isbn[i]=='-')
            i--;
        else
            num[i] = int(isbn[i]-'0');
    }


    //输入校验码
    char x;
    int jiao;
    cin>>x;
    cin>>x;
    if(x=='X')
        jiao = 10;
    else
        jiao = int(x-'0');
    
    //计算校验码
    int yan=0;
    for(int i=1;i<=9;i++)
        yan += i*num[i-1];
    if(yan%11==jiao)
        cout<<"Right";
    else{
        for(int i=0; i<9;i++){
            if(i==1 || i== 4)
                cout<<'-';
            cout<<num[i];
        }
        cout<<"-";
        if(yan%11==10)
            cout<<"X";
        else
            cout<<yan%11;
    }
    return 0;
        
}