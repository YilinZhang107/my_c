#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // map<char,int> now,next;
        int a[26] = {0}, b[26] = {0};
        int i = 1;
        for(char c: words[0]){
            a[c-'a']++;
        }
        while(words.size() > 1 && i!= words.size()){
            memset(b,0,sizeof(b));
            for(char c: words[i]){ b[c-'a']++; }
            if(same(a,b)){
                words.erase(words.begin()+i);
            }
            else{
                for(int j=0;j<26;j++) a[j] = b[j];
                i++;
            }
        }
        return words;
    }

    bool same(int* a, int* b){
        for(int i=0;i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

};


int main(){
    Solution s;
    // int a[26] = {0}, b[26] = {0};
    vector<string> words = {"a","b","c","d","e"};
    words = s.removeAnagrams(words);
    for(string str: words){
        cout<<str<<endl;
    }
    return 0;
}