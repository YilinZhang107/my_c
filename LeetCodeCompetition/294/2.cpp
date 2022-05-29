#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> need;
        for(int i=0;i<capacity.size();i++){
            need.push_back(capacity[i]-rocks[i]);
        }
        sort(need.begin(),need.end());
        int i=0;
        while(i < need.size()){
            if(additionalRocks < need[i]){
                break;
            }
                
            additionalRocks -= need[i];
            i++;
        }
        return i;
    }
};