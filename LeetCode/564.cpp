//hard
//找规律
using ll = long long;
constexpr ll Pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000};// 1 ~ 1e17;
class Solution {
    ll getPld(const ll &num){// 获取由 num 前面一半数字构成回文的数
        string str = to_string(num);
        for(int i = 0, j = str.size()-1; i < j; ++i, --j) str[j] = str[i];
        return stol(str);
    }
public:
    string nearestPalindromic(string s) {
        int n = s.size();
        ll ss = stol(s);
        if(ss == 11) return "9"; //所有的一位数都是回文所以需要特判。

        ll ans1 = ss, ans2 = ss;
        for(int i = 0; ans1 >= ss; ans1 = getPld(ss - Pow[i]), ++i);
        for(int i = 0; ans2 <= ss; ans2 = getPld(ss + Pow[i]), ++i); 
        if(ss-ans1 <= ans2-ss) return to_string(ans1);
        else return to_string(ans2);
    }
};
