#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        int p=0, times;
        string t, ans;
        while(p != s.size()){
            if(s[p] >= '0' && s[p]<='9'){  //isdigit(s[p])
                t = "";
                while(s[p] >= '0' && s[p]<='9'){
                    t += s[p];
                    p++;
                }
                stk.push(t);
            }
            else if(s[p] == '[' || (s[p] >= 'a' && s[p]<='z')){
                t = s[p++];
                stk.push(t);
            }
            else{
                t = ""; //把括号之间的字符拼接起来
                while(stk.top() != "["){
                    t.insert(0, stk.top());
                    stk.pop();
                }
                stk.pop();//出左括号
                times = stoi(stk.top());
                stk.pop();
                ans = "";
                while(times--){
                    ans += t;
                }
                stk.push(ans);
                p++;
            }
        }
        ans = "";
        while(!stk.empty()){
            ans.insert(0, stk.top());
            stk.pop();
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str = "3[a2[c]]";
    cout<<s.decodeString(str)<<endl;

}

