#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //根据数学, 必须 1/(2/3/4/...)才能得到最大值
    string optimalDivision(vector<int>& nums) {
        string result = to_string(nums[0]);
        for(int i=1; i<nums.size();i++){
            result += "/"+to_string(nums[i]);
        }
        if(nums.size()>2){
            result.insert(result.find('/')+1,"(");
            result+=")";
        }
        return result;
    }
};

//动态规划
struct Node {
    double maxVal, minVal;
    string minStr, maxStr;
    Node() {
        this->minVal = 10000.0;
        this->maxVal = 0.0;
    }
};

class Solution1 {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<vector<Node>> dp(n, vector<Node>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i].minVal = nums[i];
            dp[i][i].maxVal = nums[i];
            dp[i][i].minStr = to_string(nums[i]);
            dp[i][i].maxStr = to_string(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                for (int k = j; k < j + i; k++) {
                    if (dp[j][j + i].maxVal < dp[j][k].maxVal / dp[k + 1][j + i].minVal) {
                        dp[j][j + i].maxVal = dp[j][k].maxVal / dp[k + 1][j + i].minVal;
                        if (k + 1 == j + i) {
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/" + dp[k + 1][j + i].minStr;
                        } else {
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/(" + dp[k + 1][j + i].minStr + ")";
                        }
                    }
                    if (dp[j][j + i].minVal > dp[j][k].minVal / dp[k + 1][j + i].maxVal) {
                        dp[j][j + i].minVal = dp[j][k].minVal / dp[k + 1][j + i].maxVal;
                        if (k + 1 == j + i) {
                            dp[j][j + i].minStr = dp[j][k].minStr + "/" + dp[k + 1][j + i].maxStr; 
                        } else {
                            dp[j][j + i].minStr = dp[j][k].minStr + "/(" + dp[k + 1][j + i].maxStr + ")"; 
                        }
                    }
                }
            }
        }
        return dp[0][n - 1].maxStr;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    int totalTrips = 5;
    cout<<s.optimalDivision(nums);
    return 0;
}