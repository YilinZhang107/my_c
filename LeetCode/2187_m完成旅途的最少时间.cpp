#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //超时了...
    long long minimumTime_1(vector<int>& time, int totalTrips) {
        long long minTime = 0;
        long long trueTotalTrip = 0;
        while(trueTotalTrip < totalTrips){
            trueTotalTrip = 0;
            minTime++;
            for(int i=0; i<time.size(); i++)
                trueTotalTrip += minTime/time[i];
        }
        return minTime;
    }

    //官解, 二分法,上面我的挨个找太蠢了
    long long minimumTime(vector<int>& time, int totalTrips) {
        // 判断 t 时间内是否可以完成 totalTrips 趟旅途
        auto check = [&](long long t) -> bool {
            long long cnt = 0;
            for (int period: time) {
                cnt += t / period;
            }
            return cnt >= totalTrips;
        };
        
        // 二分查找下界与上界
        long long l = 1;
        long long r = (long long) totalTrips * *max_element(time.begin(), time.end());
        // 二分查找寻找满足要求的最小的 t
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
              l = mid + 1;
            }
        }
        return l;
    }
};

int main(){
    Solution s;
    vector<int> time = {1,2,3};
    int totalTrips = 5;
    cout<<s.minimumTime(time,totalTrips);
    return 0;
}