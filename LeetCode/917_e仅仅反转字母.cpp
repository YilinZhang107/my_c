#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//自己用了队列,先进先出,两次扫描
    string reverseOnlyLetters(string s) {
        queue<char> english;
        for(int i=0; i<s.length(); i++){
            if((s[i] >= 'a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
               english.push(s[i]);
               s[i] = 10;
            } 
        }
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == 10){
                s[i] = english.front();
                english.pop();
            } 
        }
        return s;
    }

    //官方, 使用双指针从头到尾扫描
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) { // 判断左边是否扫描到字母
                left++;
            }
            while (right > left && !isalpha(s[right])) { // 判断右边是否扫描到字母
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }


};

