#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans = 0;
        ans = special[0] - bottom;
        if(*(special.end()-1) != top) 
            ans = max(ans, top - *(special.end()-1));
        if(special.size()==1)
            return ans;
        else{
            for(int i=1;i<special.size();i++){
                if(special[i]- special[i-1]-1 > ans)
                    ans = special[i]- special[i-1]-1;
            }  
            return ans; 
        }
    }
};

int main(){
    Solution s;
    vector<int> spe = {38};
    cout<<s.maxConsecutive(6,39,spe);
    return 0;
}