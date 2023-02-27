#include<bits/stdc++.h>
using namespace std;  

// struct Cmp
// {
//     bool operator () (int const &a,int const &b)const
//     {
//         if(a.num!=b.num)
//             return a.num<b.num;
//         else return a.i<b.i;
//     }
// };

int main(){
    int m,n;
    cin>>m>>n;
    map<vector<int>, string,greater<vector<int>> > mp;
    for(int i=0;i<m;i++){
        string s;
        vector<int> v;
        int win,pin,lose,goal,diu;
        cin>>s>>win>>pin>>lose>>goal>>diu;
        v.push_back(3*win+pin);
        v.push_back(goal-diu);
        mp[v] = s;
    }
    int j=0;
    for(auto i=mp.begin(); i!= mp.end()&&j<n; i++,j++){
        cout<<j+1<<" "<<i->second<<" "<<i->first[0]<<" "<<i->first[1]<<endl;
    }
    return 0;

}