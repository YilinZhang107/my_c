#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//最小前缀法, (使用的必定是前面的数字中最小的那个)
    int maximumDifference_1(vector<int>& nums) {
        int maxDiff = 0;
        int minFront = nums[0];
        for(int i=0; i<nums.size()-1; i++){
            minFront = (nums[i] < minFront) ? nums[i] : minFront;
            maxDiff = (nums[i+1]-minFront)>maxDiff ? nums[i+1]-minFront:maxDiff;
        }
        if(maxDiff == 0)
            return -1;
        else
            return maxDiff;
    }


    //暴力法不可取
    int maximumDifference(vector<int>& nums) {
        int maxDiff = 0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] - nums[i] > maxDiff)
                    maxDiff = nums[j]-nums[i];
            }
        }
        if(maxDiff == 0)
            return -1;
        else
            return maxDiff;
    }

};