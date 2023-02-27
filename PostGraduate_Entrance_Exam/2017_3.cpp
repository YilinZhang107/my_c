#include<bits/stdc++.h>
using namespace std;

int timeChange(string time){
    int ans=0;
    int c = time.find(':');
    if(c==1)
        ans += (time[0]-'0') *60;
    else
        ans += (time[0]-'0')*10*60 + (time[1]-'0')*60;
    time = time.substr(c+1);
    ans += (time[0]-'0')*10 + (time[1]-'0');
    return ans; 
}


int main(){
    map<string, int> mp;
    string name,times,timee;
    int n;//先输入有多少组数据
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>times>>timee;
        if(mp.count(name))
            mp[name] += timeChange(timee) - timeChange(times);
        else
            mp[name] = timeChange(timee) - timeChange(times);
    }
    for(auto i = mp.begin(); i!= mp.end(); i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    return 0;
}