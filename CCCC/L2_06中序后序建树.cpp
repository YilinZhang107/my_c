#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
int n;

vi post,in;//postOrder后序  inOrder中序
struct node{
    int l,r;
}nodes[55];

//        后序的左右      中序的左右
int build(int pl,int pr,int il,int ir){
    if(pl>pr) return 0;
    if(il>ir) return 0;
    int head = post[pr];
    //在中序遍历中找到根节点,分成左右子树递归建树
    int pos = il;
    while(in[pos] != head)
        pos++;
    int len = pos-il;//左串的长度

    nodes[head].l = build(pl, pl+len-1, il, pos-1);
    nodes[head].r = build(pl+len, pr-1, pos+1, ir);
    return head;
}

int main(){
    cin>>n;
    int i;
    int t;
    for(i=0;i<n;i++){
        cin>>t;
        post.push_back(t);
    }
    for(i=0;i<n;i++){
        cin>>t;
        in.push_back(t);
    }
    int head = build(0,n-1,0,n-1);
    
    //输出,本来可以简单些,但为了控制格式
    
    queue<int> q;
    cout<<head;
    if(nodes[head].l)
            q.push(nodes[head].l);
        if(nodes[head].r)
            q.push(nodes[head].r);
    while(!q.empty()){
        int k = q.front();
        cout<<" "<<k;
        q.pop();
        if(nodes[k].l)
            q.push(nodes[k].l);
        if(nodes[k].r)
            q.push(nodes[k].r);
    }
    return 0;
}