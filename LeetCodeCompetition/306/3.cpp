#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int use[10] = {0};
    string smallestNumber(string pattern) {
        string ans = "";
        for(int i=0; i<=pattern.length(); i++){
            ans += '0';
        }
        
        for(int i=0;i<=pattern.length();i++){
            if(i==pattern.length()){
                if(pattern[i-1] == 'I'){
                    ans[i] = nowmin();
                }else{
                    ans[i] = nowmin();
                    int j=i;
                    while(j>0 && ans[j-1] == '0'){//回退填d
                        ans[j-1] = nowmin();
                        j--;
                    }
                }
            }
            else{
                if(pattern[i] == 'I'){
                    ans[i] = nowmin();
                    int j=i;
                    while(j>0 && ans[j-1] == '0'){//回退填d
                        ans[j-1] = nowmin();
                        j--;
                    }
                }
            }
        }
        return ans;
    }
    char nowmin(){
        for(int i=1;i<10;i++){
            if(use[i] == 0){
                use[i]++;
                return '0'+i;   
            }
        }
        return '0'; 
    }
};