//出三个整数 a,b,c(0\le a,b,c \le 100)a,b,c
//(0≤a,b,c≤100)，要求把这三位整数从小到大排序。
#include<bits/stdc++.h>
using namespace std;
/*
int main(){  //通过判断来枚举
    int a,b,c;
    cin >> a>> b>> c;
    if(a<b){
        if(a<c){
            if(b<c)
                cout<< a<<" "<< b<<" "<<c;
            else
                cout<< a<<" "<<c<<" "<<b;
        }
        else
            cout<< c<<" "<<a<<" "<<b;
    }
    else{
        if(b<c){
            if(c<a)
                cout<< b<<" "<<c<<" "<<a;
            else
                cout<< b<<" "<<a<<" "<<c;
        }
        else
            cout<< c<<" "<<b<<" "<<a;
    }
    return 0;    
}
*/
int main(){  //利用系统函数的快排sort
    int s[3];
    cin >> s[0]>>s[1]>>s[2];
    sort(s,s+3); //表示排序数组从0-3的位置，sort默认从小到大
    cout<<s[0]<<' '<<s[1]<<' '<<s[2];
}
/*
int main(){  //利用swap枚举，更简单
    int a,b,c;
    if(a>b)
        swap(a,b);
    if(b>c)
        swap(b,c);
    if(a>c)
        swap(a,c);
    cout<<s[0]<<' '<<s[1]<<' '<<s[2];
    return 0;   
}
*/

/* 桶排
int main(){
  ;  
}
*/