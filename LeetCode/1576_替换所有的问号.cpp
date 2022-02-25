/*
给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。

注意：你 不能 修改非 '?' 字符。

题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。

在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int index = 0;//指针
        while(index < s.length()){
            if(s[index] == '?'){
                s[index] = change(s, index);
            }
            index++;
        }
        return s;
    }
    char change(string s, int index){
        if((index+1) < s.length() && s[index+1] == '?'){
            s[index+1] = change(s, index+1);            
        }

        char preChanged = 'a';
        while((index>0 && preChanged == s[index-1]) || ((index+1) < s.length() && preChanged == s[index+1]))
            preChanged++;
        return preChanged;
    }

};


//==========test===========
int main(){
    Solution s;
    string str = "??yw?ipkj?";
    str = s.modifyString(str);
    cout<<str;
    return 0;
}