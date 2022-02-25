#include<bits/stdc++.h>
using namespace std;

void max(int a,int b,int c=0){
    int m=0;
    if(a>b){
        if(a>c)
            m = a;
        else
            m = c;
    }
    else{
        if(b>c)
            m = b;
        else
            m = c;
    }
    cout<<"max = "<<m;
}

//求2个或3个正整数中的最大数，用带有默认参数的函数实现。
int  main(){
    int a,b;
    cin>>a>>b; 
    if(cin.get() != '\n'){
        int c;
        cin>>c;
        max(a,b,c);
    }
    else
        max(a,b);
    return 0;
}

