#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        auto getMinute = [](string time){
            return (int)((time[0]-'0')*10+(time[1]-'0'))*60 + (time[3]-'0')*10+(time[4]-'0');
        };

        //如果长于1440则必定有重复
        if(timePoints.size() > 1440)
            return 0;

        short length = timePoints.size();
        vector<int> timeMinutes(length);
        for(int i=0; i<length; i++)
            timeMinutes[i] = getMinute(timePoints[i]);
        sort(timeMinutes.begin(),timeMinutes.end());
        int minest = INT_MAX;
        for(auto i=timeMinutes.begin(); i!=timeMinutes.end()-1; i++){
            if(*(i+1)-*i < minest)
                minest = *(i+1)-*i;
        }
        minest = min(minest, timeMinutes[0]+1440-timeMinutes[length-1]);
        return minest;
    }
};

int main(){
    Solution s;
    vector<string> time = {"00:00","23:59","00:00"};
    cout<<s.findMinDifference(time);
    
    return 0;
}