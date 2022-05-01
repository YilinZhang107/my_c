#include<bits/stdc++.h>
using namespace std;
//63/77

class Solution {
public:
    // map<char, int> mp;
    int cnt[26];
    long long appealSum(string s) {
        long long ans=0;
        ans+=s.size();
        
        for(int i=2;i<=s.size();i++){
            memset(cnt,0,sizeof(cnt));
            // mp.clear();
            for(int j=i-1; j<s.size();j++){
                if(j==i-1){
                    for(int l=0; l<=j; l++){
                        cnt[s[l]-'a']++;
                        // if(mp.count(s[l])) mp[s[l]]++;
                        // else mp[s[l]] = 1;
                    }
                    ans += cal();
                }else{
                    cnt[s[j-i]]--;
                    cnt[s[j]]++;
                    ans+=cal();
                }
            }   
        }
        return ans;
    }

    int cal(){
        int sum = 0;
        for(int i=0;i<26;i++){
            if(cnt[i] != 0)
                sum++;
        }
        // for(auto i:mp){
        //     if(i.second!=0)
        //         sum++;
        // }
        return sum;
    }
};


int main(){
    Solution s;
    // vector<int> vi = {1,2,3,4};
    cout<<s.appealSum("abbca");
    return 0;
}