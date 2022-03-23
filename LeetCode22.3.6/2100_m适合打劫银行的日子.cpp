#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //硬要说这个方法时间复杂度也是n
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> goodDays;
        if(security.size()<=time*2)
            return goodDays;
        
        int front = 0, back = 0;
        for(int i=0; i<(security.size()-time); i++){
            if(i>0 && security[i-1]>=security[i])
                front++;
            else
                front=0;
            
            if(front >= time){//前面的日子够了
                bool fit = true;
                for(int j=1; j<=time; j++){
                    if(security[i+j-1]>security[i+j])
                        fit = false;
                }
                if(fit){
                    goodDays.push_back(i);
                    while(i<(security.size()-time-1) && security[i]>=security[i+1]){//顺势判断后一位,应该相同数字的情况比较多
                        if(security[i+time]<=security[i+time+1]){
                            goodDays.push_back(i+1);
                            i++;
                        }else
                            break;
                    }
                }
            }
        }
        return goodDays;
    }
    //官方的动态规划n,n, 很妙
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }

        vector<int> ans;
        for (int i = time; i < n - time; i++) {
            if (left[i] >= time && right[i] >= time) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,3,3,3,5,6,2};
    nums = s.goodDaysToRobBank(nums,2);
    return 0;
}