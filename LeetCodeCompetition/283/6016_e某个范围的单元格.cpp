#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> range;
        for(int i=0; i<=s[3]-s[0]; i++){
            string t = "";
            t += s[0]+i;  
            for(int j=s[1]-'0'; j<=s[4]-'0'; j++){
                string t2 = "";
                t2+='0'+j;
                range.push_back(t+t2);
            }
        }
        return range;
    }
};

int main(){
    Solution s;
    string str = "A1:F1";
    vector<string> range = s.cellsInRange(str);
    return 0; 
}