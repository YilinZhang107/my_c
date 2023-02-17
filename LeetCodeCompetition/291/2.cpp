#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int minL = 999999;
        map<int ,int > mp;
        for(int i=0;i<cards.size();i++){
            if(mp.count(cards[i])){
                if(i-mp[cards[i]] < minL)
                    minL = i-mp[cards[i]];
                mp[cards[i]] = i;
            }
            else{
                mp[cards[i]] = i;
            }
        }
        return (minL==999999) ? -1 :minL;
    }
};

int main(){
    Solution s;
    
}