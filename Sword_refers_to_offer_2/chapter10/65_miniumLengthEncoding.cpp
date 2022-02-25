#include<bits/stdc++.h>
using namespace std;
/*
给定一个含有n个单词的数组，我们可以把它们编码成一个字符串和n个下标。假如给定单词数组["time", "me", "bell"]，我们可以把它们编码成一个字符串"time#bell#"，然后这些单词就可以通过下标[0, 2, 5]得到。对于每一个下标，我们都可以从编码之后得到的字符串中相应的位置开始扫描直到遇到"#"字符前所经过的子字符串为单词数组中的一个单词。例如从"time#bell#"下标2的位置开始扫描直到遇到"#"前经过子字符串"me"是给定单词数组的第二个单词。

给我们一个单词数组，请问按照上述规则把这些单词编码之后得到的最短字符串的长度是多少？如果输入是字符串数组["time", "me", "bell"]，编码之后最短的字符串是"time#bell#"，长度是10。*/

class TrieNode{
    TrieNode* children[26];
public:
    int count;
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        count = 0;
    }
    TrieNode* get(char c){
        if(children[c - 'a'] == NULL){
            children[c- 'a']= new TrieNode();
            count++;
        } 
        return children[c-'a'];
    }
};


class Solution {
public:
    int minimumLengthEncoding_2(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for(int i=0; i<(int)words.size(); i++){
            string word = words[i];
            TrieNode* cur = trie;
            for(int j=word.length()-1; j>=0; j--){
                cur = cur->get(word[j]);
            }
            nodes[cur] = i;
        }    
        int ans = 0;
        for(auto& [node, idx] : nodes){
            if(node->count == 0){
                ans += words[idx].length()+1;
            }
        }
        return ans;
    }

    //用哈希表,存入不相同的单词
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (const string& word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }

   
};


int main(){
    vector<string> words = {"main", "in", "dell"};
    Solution s;
    cout<<s.minimumLengthEncoding_2(words);
    return 0;
}