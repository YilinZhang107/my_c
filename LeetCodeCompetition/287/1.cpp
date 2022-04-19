#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int ans=0,now, past;
        now = 60*stol(current.substr(0,2)) + stol(current.substr(3,2));
        past = 60*stol(correct.substr(0,2)) + stol(correct.substr(3,2));

        now = past - now;
        
        ans += now/60;
        now %=60;
        
        ans += now/15;
        now %=15;
        
        ans += now/5;
        now %=5;

        ans+=now/1;
        
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.convertTime("11:30", "11:31");
    return 0;
}