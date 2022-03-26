#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //左前缀为L一定不会撞, 右后缀为R一定不会撞, 中间不为S的全部撞一次
    int countCollisions_best(string directions) {
        int leftNum = 0, rightNum = 0, i=0;
        while(directions.size()>i && directions[i++] == 'L')
            leftNum++;
        directions.erase(0,leftNum);
        i = directions.size()-1;
        while(i>=0 && directions[i--] == 'R')
            rightNum++;
        directions.erase(directions.size()-rightNum, rightNum);
        return directions.size()-count(directions.begin(),directions.end(), 'S');
    }

    //思路被书那道题束缚了
   
};

int main(){
    vector<int> nums = {6,6,6};
    string str = "LLRR";
    Solution s;
    cout<<s.countCollisions_best(str);
    return 0;
}