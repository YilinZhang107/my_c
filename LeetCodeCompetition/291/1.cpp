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


class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        m = 0;
        for(int i=0,i<number.size();i++){
            if(number[i] == digit){
                //bug(number.replace(number.begin()+i,number.begin()+i+1,""));
                string t = number;
                if(ans == "" || ans < t.replace(t.begin()+i,t.begin()+i+1,"")) {
                    t = number;
                    ans = t.replace(t.begin()+i,t.begin()+i+1,"");
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    // cout<<("123">"231")<<endl;
    cout<<s.removeDigit("1231",'1');
    


    return 0;
}