#include<bits/stdc++.h>
using namespace std;
int n,m,k;

double ans[10005];

int main(){
    cin>>n>>k>>m;
    int t;
    memset(ans,0.0,sizeof(ans));
    for(int i=0;i<n;i++){
        multiset<int> now;
        for(int j=0;j<k;j++){
            cin>>t;
            now.insert(t);
        }
        double avg = 0.0;
        now.erase(now.begin());
        now.erase(--now.end());
        for(auto j=now.begin(); j!= now.end(); j++){
            avg+=*j;
        }
        ans[i] = avg/(k-2);
    }  
    sort(ans,ans+n);
    for(int i=n-m;i<n;i++){
        if(i==n-m)
            printf("%.3f", ans[i]);
        else
            printf(" %.3f", ans[i]);
    }

    return 0;
}