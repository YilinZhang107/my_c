#include<bits/stdc++.h>
using namespace std;

struct node{
    int v;
    int next;
}nodes[100005];
int n;
vector<int> ini;
int le,ri,head;

int main(){
    cin>>head>>n;
    int t,t1,t2;
    for(int i=0;i<n;i++){
        cin>>t>>t1>>t2;
        nodes[t].v = t1;
        nodes[t].next = t2;
    }
    while(head != -1){
        ini.push_back(head);
        head = nodes[head].next;

    }
    le=0;ri = ini.size()-1;
    head = ini[ini.size()-1];
    while(le<ri){
        nodes[ini[ri]].next = ini[le];
        nodes[ini[le]].next = ini[ri-1];
        le++;
        ri--;
    }
    if(ini.size()&1){
        nodes[ini[ini.size()/2]].next = -1;
    }else{
        nodes[ini[ini.size()/2-1]].next = -1;
    }
    while(head != -1){
        if(nodes[head].next != -1)
            printf("%05d %d %05d\n",head,nodes[head].v,nodes[head].next);
        else
            printf("%05d %d %d\n",head,nodes[head].v,nodes[head].next);
        head = nodes[head].next;
    }
    return 0;
}