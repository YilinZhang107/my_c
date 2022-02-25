#include<bits/stdc++.h>
using namespace std;


//这题是穷举法, 用两个指针分别确定第一个数和第二个数,然后遍历第三个数,
//感觉边界条件很重要
class Solution {
public:
    bool judge(string &num, long first, long second, int third, int n){
        if(third == n) //此时num已经遍历完了, 并且都符合要求
            return true;
        for(int i=third; i<n; i++){
            if(num[third] == '0' && i>third)
                return false;
            long t = stol(num.substr(third, i-third+1));
            if(t > first + second)  //当前数字已经大于2数之和,不需要再增加第三个数位数
                return false;
            if(t == first + second){
                if(judge(num, second, t, i+1, n))
                    return true;
                break;
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size(); //字符串长度

        for(int i=0; i<n/2; i++){//第一个数字的长度不可能超过总长一半
            if(num[0]=='0' && i>0)
                return false; //不应该出现01,02这种数
            for(int j=i+1; j<i+1 +(n-i-1)/2; j++){//第二个数的长度
                if(num[i+1] == '0' && j>i+1)//是否是0开头的数字
                    continue;
                //第一个数和第二个数
                long first = stol(num.substr(0,i+1));
                long second = stol(num.substr(i+1,j-i));
                //判断后续数,是否可以构成累加序列
                if(judge(num, first, second, j+1, n))
                    return true;
            }
        }
        return false;
    }  
};

int main(){
    Solution s;
    string str = "12012122436";
    cout<<s.isAdditiveNumber(str);
    return 0;
}