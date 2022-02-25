#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//自己写, 有点麻烦
    string complexNumberMultiply(string num1, string num2) {
        int num1t = stol(num1.substr(0, num1.find('+'))),//得到实部
            num2t = stol(num2.substr(0, num2.find('+')));
        
        num1.erase(0,num1.find('+')+1);//先去掉实部
        num2.erase(0,num2.find('+')+1);

        int num1v = stol(num1.substr(0, num1.size()-1)),
            num2v = stol(num2.substr(0, num2.size()-1));//得到虚部
        
        int resultt = num1t*num2t - 1*(num1v*num2v),
            resultv = num1t*num2v + num2t*num1v;
        
        string result = to_string(resultt) +"+"+ to_string(resultv)+ "i";
        return result; 
    }

    //大神思路,注意sscanf用法
    string complexNumberMultiply_2(string num1, string num2) {
        int a1, b1, a2, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        char ans[20];
        sprintf(ans, "%d+%di", a1*a2-b1*b2, a1*b2+a2*b1);
        return ans;
    }
};

int main(){
    Solution s;
    string num1 = "1+-1i", num2 = "1+-1i";
    cout<<s.complexNumberMultiply(num1,num2);
    return 0;
}