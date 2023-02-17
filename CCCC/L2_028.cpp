#include<bits/stdc++.h>
using namespace std;
//傻逼模拟题, 最后也没做出来
vector<int> e[1005];
int sex[1005];
int n,m,k,t;
bool cmp(int a, int b){
    return abs(a)<abs(b);
}
double qa[1005],qb[1005];
int main(){
    cin>>n>>m;
    string s;
    memset(sex,-1,sizeof(sex));
    for(int i=0;i<m;i++){
        cin>>k;
        while(k--){
            cin>>s;
            t = abs(stol(s));
            if(s.size()>1){
                e[i].push_back(t);
                sex[t] = 0;//woman
            }else{
                e[i].push_back(t);
                sex[t] = 1;
            }
        }
    }
    string sa,sb;
    int a,b;
    cin>>sa>>sb;
    a = abs(stol(sa));
    b = abs(stol(sb));
    double ma=-1.0,mb=-1.0;
    memset(qa,0.0,sizeof(qa));
    memset(qb,0.0,sizeof(qb));

    for(int i=0;i<m;i++){
        if(count(e[i].begin(),e[i].end(),a)){
            for(int j = 0;j<e[i].size(); j++){
                if(sex[e[i][j]] != sex[a]){
                    qa[e[i][j]] += 1.0/e[i].size();
                    ma = max(qa[e[i][j]], ma);
                }
            }
        }   
    }
    for(int i=0;i<m;i++){
        if(count(e[i].begin(),e[i].end(),b)){
            for(int j = 0;j<e[i].size(); j++){
                if(sex[e[i][j]] != sex[b]){
                    qb[e[i][j]] += 1.0/e[i].size();
                    mb = max(qb[e[i][j]], mb);
                }
            }
        }   
    }

    // set<int> aa,ab;
    // for(int i=0;i<n;i++){
    //     if(qa[i] > ma){
    //         aa.clear();
    //         ma = qa[i];
    //         aa.insert(i);
    //     }else if(qa[i] == ma) 
    //         aa.insert(i);
    // }
    // for(int i=0;i<n;i++){
    //     if(qb[i] > mb){
    //         ab.clear();
    //         mb = qb[i];
    //         ab.insert(i);
    //     }else if(qb[i] == mb) 
    //         ab.insert(i);
    // }
    if(qa[b]==ma && qb[a]==mb){
        cout<<sa<<" "<<sb;
    }else{
        for(int  i = 0; i<n; i++){
            if(qa[i] == ma){
                if(sex[a] == 0)
                    cout<<sa<<" "<<i<<endl;
                else
                    cout<<sa<<" -"<<i<<endl;
            }
        }
        for(int  i =0; i<n; i++){
            if(qb[i]==mb){
                if(sex[b] == 0)
                    cout<<sb<<" "<<i<<endl;
                else
                    cout<<sb<<" -"<<i<<endl;
            }
        }
    }
    return 0;
}