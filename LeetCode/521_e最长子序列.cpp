#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //有病这题
    int findLUSlength(string a, string b) {
         return (a==b) ? -1 : max(a.length(), b.length());
    }
};

int main(){
    Solution s;
    cout<<s.findLUSlength("aaa","aaa");
    return 0;
}