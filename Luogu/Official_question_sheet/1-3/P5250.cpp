#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int func,t,ind;
    vector<int> v;
    for(int i=0; i<n; i++){
        cin>>func;
        if(func == 1){
            cin>>t;
            ind = lower_bound(v.begin(), v.end(), t) - v.begin();
            if(!v.empty() && v[ind] == t)
                cout<<"Already Exist"<<endl;
            else
                v.insert(v.begin()+ind, t);
        }
        else{
            if(v.empty())
                cout<<"Empty"<<endl;
            else{
                cin>>t;
                ind = lower_bound(v.begin(), v.end(), t) - v.begin();
                if(ind == v.size())
                    ind = ind-1;
                else if(ind == 0){
                    ind = ind;
                }
                else{
                    if(t == v[ind])
                        ind = ind;
                    else{
                        int mincha = abs(t-v[ind]);
                        if(abs(t-v[ind-1]) <= mincha)
                            ind = ind-1;
                    }
                    
                }
                cout<<v[ind]<<endl;
                v.erase(v.begin()+ind);
            }
            
        }
    }
    return 0;
}