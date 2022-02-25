#include<bits/stdc++.h>
using namespace std;

/*
动态规划
我们设 {dp}[i][j]dp[i][j] 代表当前长度为 ii 且以字符 jj 为结尾的字符串的数目，其中在此 j = {0,1,2,3,4}j=0,1,2,3,4 分别代表元音字母 {\texttt{`a'}, \texttt{`e'}, \texttt{`i'}, \texttt{`o'}, \texttt{`u'}}‘a’,‘e’,‘i’,‘o’,‘u’，通过以上的字符规则，我们可以得到动态规划递推公式如下：

dp[i][0]=dp[i−1][1]+dp[i−1][2]+dp[i−1][4]
dp[i][1]=dp[i−1][0]+dp[i−1][2]
dp[i][2]=dp[i−1][1]+dp[i−1][3]
dp[i][3]=dp[i−1][2]
dp[i][4]=dp[i−1][2]+dp[i−1][3] 

实际计算过程中只需要保留前一个状态即可推导出后一个状态，计算长度为 ii 的状态只需要长度为 i-1i−1 的中间变量即可，i-1i−1 之前的状态全部都可以丢弃掉。计算过程中，答案需要取模 1\text{e}9+71e9+7
*/
class Solution{
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;
        vector<long long> dp(5, 1);
        vector<long long> ndp(5);
        for(int i=2; i<=n; i++){
            /*a前面可以为e,u i*/
            ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            ndp[1] = (dp[0] + dp[2]) % mod;
            ndp[2] = (dp[1] + dp[3]) % mod;
            ndp[3] = (dp[2]) % mod;
            ndp[4] = (dp[2] + dp[3]) % mod;
            dp = ndp;
        }
        return accumulate(dp.begin(),dp.end(),0LL) % mod;
    }
};