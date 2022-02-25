#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size()){ //始终让num2作为位数长的
            string t = num1;
            num1 = num2;
            num2 = t;
        }
        int index1 = num1.size();
        int index2 = num2.size();
        string add(index2+1,'0');
        while(index2>0){
            index1--;
            index2--;
            int t = add[index2+1]-'0';
            if(index1>=0)
                t += num1[index1]-'0';
            t += num2[index2] - '0';
            add[index2+1] = t%10 + '0';
            if(t>9)
                add[index2]++;
        }
        if(add[0]=='0')
            add.erase(0,1);
        return add;
    }
};

int main(){
    string num1 = "999";
    string num2 = "1";
    Solution s;
    string add = s.addStrings(num1,num2);
    cout<<add<<endl;
    return 0;
}