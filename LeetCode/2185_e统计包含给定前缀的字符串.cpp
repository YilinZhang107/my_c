#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int sum = 0;
        for(int i=0; i<words.size(); i++){
            int index=0;
            while(index != pref.size()){
                if(words[i][index] != pref[index])
                    break;
                index++;
            }
            if(index == pref.size())
                sum++;
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<string> words = {"leetcode","win","loops","success"};
    string pref =  "code";
    cout<<s.prefixCount(words, pref);
    return 0;
}