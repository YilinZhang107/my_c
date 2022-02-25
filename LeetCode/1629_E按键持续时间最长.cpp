#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int lastTime = 0, nowTime, maxTime = 0;
        int maxNum = 0, index = 0;
        while(index<releaseTimes.size()){
            nowTime = releaseTimes[index] - lastTime;
            if(nowTime > maxTime){
                maxTime = nowTime;
                maxNum = index;
            }
            else if(nowTime == maxTime){
                if(keysPressed[index] > keysPressed[maxNum])
                    maxNum = index;
            }
            lastTime = releaseTimes[index];
            index++;
        }
        return keysPressed[maxNum];
    }
};

int main(){
    vector<int> times = {12,23,36,46,62};
    string s = "spuda";
    Solution solution;
    cout<<solution.slowestKey(times, s);
    return 0;
}