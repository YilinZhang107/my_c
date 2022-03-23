#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//leetcode
    bool winnerOfGame(string colors) {
        int freq[2] = {0, 0};
        char cur = 'C';
        int cnt = 0;
        for (char c : colors) {
            if (c != cur) {
                cur = c;
                cnt = 1;
            } else if (++cnt >= 3) {
                ++freq[cur - 'A'];
            }
        }            
        return freq[0] > freq[1];
    }

//my
    bool winnerOfGame(string colors) {
        if(colors.size() < 3)
            return false;
        
        int nA=0, nB=0;
        for(int i=0; i<colors.size()-2; i++){
            if(colors[i] =='A'){
                if(colors[i+1] == 'A' && colors[i+2] == 'A')
                    nA++;
            }
            else{
                if(colors[i+1] == 'B' && colors[i+2] == 'B')
                    nB++;
            }
        }
        if(nA > nB)
            return true;
        else
            return false;
    }  
};