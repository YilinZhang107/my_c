#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //自己写直接构造
    string convert(string s, int numRows) {
        //特殊情况
        if(numRows==1)
            return s;

        string result;
        //循环行的次数
        for(int i=0; i<numRows; i++){
            if(i==0 || i==numRows-1){//第一行和最后一行,只需要添加一个数字
                //注意这里循环条件
                for(int j=0+i; j<s.length(); j+=numRows+numRows-2)
                    result.push_back(s[j]);
            }
            else{
                for(int j=0+i; j<s.length(); j+=numRows+numRows-2){
                    result.push_back(s[j]);
                    if(j+numRows+numRows-2-i-i < s.length())
                        result.push_back(s[j+numRows+numRows-2-i-i]);
                }
            }
        }
        return result;
    }

    //二维矩阵模拟法, 还可以进行压缩, 直接把每一行的数字添加在最后就行
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        int t = r * 2 - 2;
        int c = (n + t - 1) / t * (r - 1);
        vector<string> mat(r, string(c, 0));
        for (int i = 0, x = 0, y = 0; i < n; ++i) {
            mat[x][y] = s[i];
            if (i % t < r - 1) {
                ++x; // 向下移动
            } else {
                --x;
                ++y; // 向右上移动
            }
        }
        string ans;
        for (auto &row : mat) {
            for (char ch : row) {
                if (ch) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string a = s.convert("PAYPALISHIRING", 4);
    cout<<a;
    return 0;
}