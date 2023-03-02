#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0]>b[0])
        return 1;
    else if(a[0]<b[0])
        return 0;
    for(int i=1;i<4; i++){
        if(a[i]<b[i])
            return 1;
        else if(a[i]>b[i])
            return 0;
    }
}

int main(){
    int n,year,mon,day,score;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        scanf("%d/%d/%d %d",&year,&mon,&day,&score);
        vector<int> t;
        t.push_back(score);
        t.push_back(year);
        t.push_back(mon);
        t.push_back(day);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i=v.begin(); i!= v.end(); i++){
        printf("%d/%d/%d %d\n", (*i)[1],(*i)[2],(*i)[3],(*i)[0]);
    }
    return 0;
}