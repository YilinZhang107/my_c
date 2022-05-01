#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;

int uf[10005];

int find(int v){
    while(uf[v] != v){
        uf[v] = uf[uf[v]];//路径压缩
        v= uf[v];
    }
    return v;
}
void ui(int a,int b){
    int a1 = find(a);
    int b1 = find(b);
    if(a1 != b1) uf[b1] = a1;
}

int main(){
    cin>>n;
    int t,a,b,c,maxN = 0;
    for(int i=0;i<10005;i++) uf[i] = i;
    for(int i=1;i<=n;i++){
        cin>>k;
        vi temp;
        cin>>c;
        if(c>maxN) maxN = c;
        k--;
        while(k--){
            cin>>t;
            if(t>maxN) maxN = t;
            ui(c,t);
        }
    }
    set<int> kind;
    for(int i=1;i<=maxN;i++){
        t = find(uf[i]);
        if(!kind.count(t))  kind.insert(t);
    }
    cout<<maxN<<" "<<kind.size()<<endl;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        if(find(a) == find(b))  cout<<"Y"<<endl;
        else    cout<<"N"<<endl;
    }

    return 0;
}