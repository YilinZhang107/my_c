#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,buy;
    cin>>n;
    vector<vector<bool> > v;
    for(int i=0; i<20; i++){
        vector<bool> t(5,false);
        v.push_back(t);
    }
    while(n--){
        cin>>buy;
        if(buy>5 || buy<0){
            n++;
            continue;
        }
        bool lian = 0;
        for(int i=0; i<20; i++){
            for(int j=0; j<5-buy+1;j++){
                bool flag = 1;
                for(int l=0; l<buy; l++){
                    if(v[i][j+l] != 0)
                        flag = 0;
                }
                if(flag == 1){
                    lian = 1;//可以买到连坐
                    for(int l=0; l<buy; l++){
                        v[i][j+l] = 1;
                        cout<<i*5+j+1+l<<" ";
                    }
                    cout<<endl;
                    break;
                }
            }
            if(lian)
                break;
        }
        if(! lian){//not buy
            for(int l=0; l<buy; l++){
                for(int i=0; i<20; i++){
                    for(int j=0; j<5;j++){
                        if(v[i][j] == 0 && l<buy){
                            v[i][j]= 1;
                            cout<<i*5+j+1<<" ";
                            l++;
                        }
                    }
                }
            }
            cout<<endl;
        }
        for(int i=0; i<20; i++){
        for(int j=0; j<5;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    }

    
    return 0;
}