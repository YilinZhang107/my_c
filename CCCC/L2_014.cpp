#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;

// vector<queue<int>> dd;
//vi dd;
set<int> dd;

//不用二分查找过不了了....
int main(){
    cin>>n;
    int t,i;
    // int ans = 0;
    int max = -1;
    for(i=0;i<n;i++){
        cin>>t;
        
        int min = MAX,ind=-1;
        if(t>max){
            dd.insert(t);
            max = t;
            continue;
        }
        for(auto j=dd.begin();j!=dd.end();j++){
            if(*j < t) continue;
            else{
                dd.erase(j);
                dd.insert(t);
                ind = 1;
                break;
            }
        }
        if(ind == -1){
            dd.insert(t);
        }
    }
    cout<<dd.size();
    return 0;

    //超时
    // cin>>n;
    // int t,i;
    // // int ans = 0;
    // for(i=0;i<n;i++){
    //     queue<int> now;
    //     cin>>t;
    //     int min = MAX,ind=-1;
    //     for(int j=0;j<dd.size();j++){
    //         if(dd[j].back() < t) continue;
    //         else{
    //             if(min> dd[j].back() - t){
    //                 min = dd[j].back()-t;
    //                 ind = j;
    //             }
    //         }
    //     }
    //     if(ind!=-1){
    //         dd[ind].push(t);
    //     }else{
    //         now.push(t);
    //         dd.push_back(now);
    //     }
    // }
    // cout<<dd.size();
    // return 0;
}