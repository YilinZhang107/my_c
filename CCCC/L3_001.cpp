#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
 
int dp[maxn], choice[maxn][maxn]; //choice[i][j]表示选择第i个硬币并且已选择硬币总值为j
int n, m, c[maxn];

int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> c[i];
    }
    sort(c+1, c+1+n, greater<int>());//价值递减排序
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= c[i]; j--){
            // dp[j] = max(dp[j], dp[j-w[i]] + w[i]) 一般写法
            //最终输出的dp[V] 
            //就是V容量下能装的最大价值
            if(dp[j] <= dp[j-c[i]] + c[i]){ // 如果等于的话就是更小的序列
                dp[j] = dp[j-c[i]] + c[i];
                choice[i][j] = 1; // 标记当前选择
            }
        }
    }
    int flag = 0;
    if(dp[m] == m){ // 能够满足
        for(int i = n, j = m; i >= 1 && j >= 0; i--){
            if(choice[i][j]){
                if(flag) printf(" ");
                printf("%d", c[i]);
                flag = 1;
                j -= c[i]; // 选择第i个硬币后还需要硬币总值为j-c[i]
            }
        }
    }else{
        printf("No Solution");
    }
    return 0;
}