#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        bool n1[2001] = {false}, n2[2001] = {false};
        vector<int> not1, not2;
        vector<vector<int>> ans;
        for(int i=0; i<nums1.size(); i++){
            n1[nums1[i] + 1000] = true;
        }
        for(int i=0; i<nums2.size(); i++)
            n2[nums2[i] + 1000] = true;

        for(int i=0; i<nums1.size(); i++){
            if(!n2[nums1[i] + 1000] && count(not1.begin(),not1.end(), nums1[i])==0)
                not1.push_back(nums1[i]);
        } 
        for(int i=0; i<nums2.size(); i++){
            if(!n1[nums2[i] + 1000] && count(not2.begin(),not2.end(), nums2[i])==0)
                not2.push_back(nums2[i]);
        }   
        ans.push_back(not1);
        ans.push_back(not2);
        return ans;

    }
}




int main(){
    Soulution s;

    return 0;
}