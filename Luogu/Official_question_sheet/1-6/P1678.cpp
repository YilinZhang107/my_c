#include<bits/stdc++.h>
using namespace std;

int main(){
    //lower_bound(x) 找到数组中第一个>=x的位置, 
    //index为 该位置指针 减 首地址
    int m, n;
    cin>>m>>n;
    vector<int> v;
    int t, sum=0, ind;
    for(int i=0; i<m; i++){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        cin>>t;
        ind = lower_bound(v.begin(), v.end(), t)-v.begin();
        int mincha = abs(t- v[ind]);
        if(ind!=0)
            mincha = min(mincha, abs(t-v[ind-1]));
        sum += mincha;
    }
    cout<<sum;
    return 0;


}
