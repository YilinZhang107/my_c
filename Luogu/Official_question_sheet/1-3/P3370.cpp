// 前缀树
//map:key唯一 unordered_map:key不唯一
//默认按key值从小到大排序
#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> mp;
    int n,i;
    string s;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s;
        if(mp.count(s) != 0) //count返回值只有0和1
        //find(), 返回值是指针 != end()
            mp[s] = 1;
        else
            mp[s]++;
    }
    // set<int> se;
    cout<<mp.size();
    return 0;
}
