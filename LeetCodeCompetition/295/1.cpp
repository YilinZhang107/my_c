#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> need, have;
        for(char c: target){
            if(need.count(c))
                need[c]++;
            else {
                need[c] = 1;
                have[c] = 0;
            }
        }

        for(char c: s){
            if(need.count(c)){
                have[c]++;
            }
        }
        int ans = 99999999;
        for(auto i = have.begin(); i!=have.end(); i++){
            if(i->second / need[i->first] < ans)
                ans = i->second / need[i->first];
        }
        return ans;

    }
};

int main(){
    
}