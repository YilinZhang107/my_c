#include<bits/stdc++.h>
using namespace std;
//一个点未过,也用稳定排序了, 还是不过
struct node{
    string name;
    string sfz;
    int qk;
    string time;
    int ti;
    //int pre = 0;//last inquire
};
vector<node> nodes;
map<string, int> post;
map<string,string> bad;
bool cmp(node a,node b){
    return a.ti<b.ti;
}
bool hefa(node &a){
    
    if(a.sfz.size() == 18){
        for(int i=0;i<18;i++){
            if(a.sfz[i] > '9' || a.sfz[i]<'0')
                return false;
        }
        
        if(a.time.size() != 5) 
			return false;
        int t1 = stol(a.time.substr(0,2));
		int t2 = stol(a.time.substr(3,2));
        
        if(t1>23 || t1<0 || t2>59 || t2<0) 
			return false;
        a.ti = t1*60+t2;
        return true;
    }else{
        return false;
    }
}
int d,jg,t,s;

int main(){
    cin>>d>>jg;
    for(int i=0;i<d;i++){
        cin>>t>>s;
        nodes.clear();
        vector<map<string, int>::iterator> del;
        for(auto j=post.begin(); j!=post.end(); j++){
            j->second--;
            if(j->second==0){
				del.push_back(j);
            }
        }
        for(int j=0;j<del.size();j++) post.erase(del[j]);
        for(int j=0;j<t;j++){
            node no;
            string nam,sf,tim;
            int qk1;
            cin>>nam>>sf>>qk1>>tim;
            no.name = nam;
            no.sfz = sf;
            no.qk = qk1;
            no.time = tim;
            if(hefa(no)) {
                if(!post.count(no.sfz)){
                    nodes.push_back(no);
                } 
                if(no.qk==1)
                    bad[no.sfz] = no.name;
            }
        }
        stable_sort(nodes.begin(),nodes.end(),cmp);
        if(nodes.size()<s)
            s= nodes.size();
        for(int j=0;j<s ;j++){
            post.insert(pair<string ,int>(nodes[j].sfz, jg));
            cout<<nodes[j].name<<" "<<nodes[j].sfz<<"\n";
        }
    
    }

    for(auto j=bad.begin(); j!=bad.end(); j++){
        cout<<j->second<<" "<<j->first<<"\n";
    }
    return 0;
}