#include<bits/stdc++.h>
using namespace std;

//用一个数组存储出现次数, 取最小值即可

class Solution{
public:
    int maxBallloonNum(string text){
        int nums[5] = {0};
        for(int i=0, length=text.length(); i<length; i++){
            switch (text[i])
            {
            case 'b':
                nums[0]++;
                break;
            case 'a':
                nums[1]++;
                break;
            case 'l':
                nums[2]++;
                break;
            case 'o':
                nums[3]++;
                break;
            case 'n':
                nums[4]++;
                break;
            default:
                break;
            }
        }
        nums[2] /= 2;
        nums[3] /= 2;
        int maxNum =INT_MAX;
        for(int i=0; i<5; i++){
            if(maxNum > *(nums+i))
                maxNum = *(nums+i);
        }
        return maxNum;
    }
};

int main(){
    string text = "loonbalxballpoon";
    Solution s;
    cout<<s.maxBallloonNum(text);
    return 0;
}