#include<bits/stdc++.h>
using namespace std;

int i,j,n,head;
struct node{
    int pos = -1;
    int value;
    int next;
};

node nodes[1000005];

int main(){
    cin>>head>>n;
    vector<node> ans1,ans2;
    set<int> look;
    for(i=0;i<n;i++){
        node t;
        cin>>t.pos>>t.value>>t.next;
        nodes[t.pos] = t;
    }
    node t = nodes[head];
    int head2;
    while(1){
        if(!look.count(abs(t.value))){
            if(ans1.size()>0){
                ans1[ans1.size()-1].next = t.pos;
            }
            look.insert(abs(t.value));
            ans1.push_back(t);
        }
        else{
            
            if(ans2.size()>0){
                ans2[ans2.size()-1].next = t.pos;
            }
            ans2.push_back(t);
        }
        
        if(t.next == -1)
            break;
        t  = nodes[t.next];
    }
    ans1[ans1.size()-1].next = -1;
    if(ans2.size())
        ans2[ans2.size()-1].next = -1;



    for(i=0;i<ans1.size();i++){
        if(i!=ans1.size()-1)
            printf("%05d %d %05d\n",ans1[i].pos,ans1[i].value,ans1[i].next);
        else
         printf("%05d %d %d\n",ans1[i].pos,ans1[i].value,ans1[i].next);

        // cout<<ans1[i].pos<<" "<<ans1[i].value<<" "<<ans1[i].next<<endl;
    }
    // cout<<endl;
    for(i=0;i<ans2.size();i++){
        if(i!=ans2.size()-1)
         printf("%05d %d %05d\n",ans2[i].pos,ans2[i].value,ans2[i].next);
        else
         printf("%05d %d %d\n",ans2[i].pos,ans2[i].value,ans2[i].next);

        // cout<<ans2[i].pos<<" "<<ans2[i].value<<" "<<ans2[i].next<<endl;
    }
    return 0;
}