#include<bits/stdc++.h>
using namespace std;

struct BiTree{
    int val;
    BiTree *left,*right;
};
void insert(BiTree *t,int data){
    if(t==NULL){
        t = new BiTree();
        t->left = t->right = NULL;
        t->val = data; 
    }
    else if(t->val<data)
        insert(t->right,data);
    else if(t->val>data){
        insert(t->left,data);
    }
}
 BiTree* creat(vector<int> v){
     BiTree *t = NULL;
    //  cout<<t->left;
     for(int i=0;i<v.size();i++){
         insert(t,v[i]);
     }
     return t;
 }
 void Inorder(BiTree* t){
     if(t==NULL)
         return;
     Inorder(t->left);
     cout<<t->val<<" ";
     Inorder(t->right);
 }
int main(){
    vector<int> v;
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    BiTree *T = creat(v);
    Inorder(T);
    return 0;
}