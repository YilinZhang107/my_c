#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //暴力解法超时
    vector<int> maxScoreIndices_2(vector<int>& nums) {
        vector<int> sumGrades;
        vector<int> positions;
        for(int i=0; i<=nums.size(); i++){
            sumGrades.push_back(count(nums.begin(), nums.begin()+i, 0)+ count(nums.begin()+i, nums.end(), 1));
            //cout<<count(nums.begin(), nums.begin()+i, 0)<<endl;
            //cout<<count(nums.begin()+i, nums.end(), 1)<<endl;
        }
        int maxGrade = *max_element(sumGrades.begin(), sumGrades.end());
        for(int i=0; i<sumGrades.size(); i++){
            if(sumGrades[i] == maxGrade)
                positions.push_back(i);
        }
        return positions;
    }

    //两次遍历
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> maxPositions;
        //计算全部1的个数,即下标为0时,右部分的分数
        int maxScore = count(nums.begin(), nums.end(), 1);
        maxPositions.push_back(0);
        int score = maxScore;
        for(int i=0; i<nums.size(); i++){
            //从左向右遍历,碰到0加1
            if(nums[i] == 0){
                score++;
                if(score==maxScore)
                    maxPositions.push_back(i+1);
                else if(score>maxScore){
                    maxPositions.clear();
                    maxPositions.push_back(i+1);
                    maxScore = score;
                }
            }//碰到1减1
            else
                score--;
        }
        return maxPositions;    
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0,1,0};
    vector<int> Score = s.maxScoreIndices(nums);
    return 0;
}