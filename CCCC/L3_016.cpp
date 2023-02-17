#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 99999999
#define INF 0x3f
#define endl '\n'
#define _for(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a; i<=b;i++)
#define bug(a)  cout<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
int n,m,k;
//建立二叉搜索树

struct node{
	node* fa = nullptr;
	int val;
	node *l = nullptr,*r = nullptr;
};

node* myIn(int v,node *head, node *f){
	node *now = new node;
    now->val = v;
    if(head == nullptr) {
    	head = now;
    	head->fa = f;
        head = now;
	}
    else{
    	//bug(head->val);
    	if(v< head->val){
    		head->l = myIn(v, head->l, head);
		}else if(v >= head->val){
			head->r = myIn(v, head->r, head);
		}
	}
    return head;
}
node* find(int v, node* head){
    if(head == nullptr)
        return nullptr;
	if(head->val == v)
		return head;
	if(v<head->val)
		return find(v,head->l);
	else{
		return find(v,head->r);
	}
}

int  level(int v, node* head,int a){
	if(head == nullptr)
        return -1;
    a++;
	if(head->val == v)
		return a;
    
	if(v<head->val)
		return level(v,head->l, a);
	else
		return level(v,head->r, a);
	
}

int main(){
    cin>>n;
    node* head = new node;
    int t;
    cin>>t;
    head->val = t;
    rep(i,2,n){
    	cin>>t;
		myIn(t,head,nullptr);
	}
	cin>>m;
	getchar();
	rep(i,1,m){
		string s;
		getline(cin,s);
		int a,b;
		int yes = 1;
		node* v;
		if(s.find("is the root")!=string::npos){
			a = stol(s.substr(0, s.find(" ")));
			if(a != head->val) yes = 0; 
		}else if(s.find("are siblings")!=string::npos){
			a = stol(s.substr(0, s.find(" ")));
			s = s.substr(s.find(" ")+5);
			b = stol(s.substr(0, s.find(" ")));
			v = find(a,head);
            if(v == nullptr){
                yes = 0;
            }else if(v->fa->l->val==a){
				if(v->fa->r->val!=b) yes= 0;
			}else{
				if(v->fa->l->val != b) yes= 0;
			}
		}else if(s.find("is the parent of")!=string::npos){
			a = stol(s.substr(0, s.find(" ")));
			b = stol(s.substr(s.rfind(" ")));
			v = find(b,head);
			if(v == nullptr){
                yes = 0;
            }else if(v->fa==nullptr || v->fa->val != a) yes= 0; 
		}else if(s.find("is the left child of")!=string::npos){
			a = stol(s.substr(0, s.find(" ")));
			b = stol(s.substr(s.rfind(" ")));
			v = find(b,head);
			if(v == nullptr){
                yes = 0;
            }else if(v->l==nullptr ||v->l->val != a) yes= 0; 
		}else if(s.find("is the right child of")!=string::npos){
			a = stol(s.substr(0, s.find(" ")));
			b = stol(s.substr(s.rfind(" ")));
			v = find(b,head);
			if(v == nullptr){
                yes = 0;
            }else if(v->r==nullptr ||  v->r->val != a) yes= 0; 
		}else if(s.find("are on the same level")!=string::npos){
			a = stol(s.substr(0, s.find(" ")));
			s = s.substr(s.find(" ")+5);
			b = stol(s.substr(0, s.find(" ")));
            a = level(a,head,0);
            b = level(b,head,0);
			if(a != b || a==-1 || b ==-1 ) yes = 0;
		}
		if(yes) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	

    return 0;
}