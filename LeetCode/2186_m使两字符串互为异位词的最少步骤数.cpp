#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int letter1[26] = {0}, letter2[26] = {0};
        for(auto i=s.begin(); i!=s.end(); i++)
            letter1[*i-'a']++;
        for(auto i=t.begin(); i!=t.end(); i++)
            letter2[*i-'a']++;
        int sum = 0;
        for(int i=0; i<26; i++)
            sum += abs(letter1[i] - letter2[i]);
        
        return sum;
    }
};

int main(){
    Solution s;
    string ss =  "night";
    string t =  "thing";
    cout<<s.minSteps(ss,t);
    return 0;
}