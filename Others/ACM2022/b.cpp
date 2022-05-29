#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 99999999
#define INF 0x3f
#define endl '\n'
#define _for(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a; i<=b;i++)
#define bug(a)  cout<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
int n,m,k;


int main(){
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int len = s.size();
    int al = 0, a=0;   
    int last = 1;//上一个是什么

    for(int i=0; i<len; i++){ //三个0在一起或开头末尾两个0 则寄
        if( s[i] == '0' && 
            (i+1<len && s[i+1]=='0') &&
            (i==0 || i+2==len || (i+2<len && s[i+2]=='0'))){
            // bug(i);
            cout<<"-1";
            return 0;
        }
    }

    int i= 0;
    while(i < s.size()){
        if(s[i]=='0'){
            if(i>0 && s[i-1] == '1'){
                s.replace(i-1, 2, "");
                i--;
                al++;
            }else if(i+1 < s.size() && s[i+1]=='1'){
                s.replace(i,2,"");
                al++;
            }else{
                cout<<"-1";
                return 0;
            }
        }
        else 
            i++;
    }
    len = s.size();
    cout<<max(al, len);
    return 0;
}