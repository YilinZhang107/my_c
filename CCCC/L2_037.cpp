#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,smax;
    cin>>n>>m>>smax;

    vector<queue<char> > guidao;
    for(int i=0;i<n;i++){
        queue<char> gui;
        string s;
        cin>>s;
        for(char c:s)
            gui.push(c);
        guidao.push_back(gui);
    }
    stack<char> kuang;
    vector<char> ans;
    int func;
    while(1){
        cin>>func;
        if(func == -1)
            break;
        else if(func == 0){
            if(!kuang.empty()){
                ans.push_back(kuang.top());
                kuang.pop();
            }
        }
        else{
            if(!guidao[func-1].empty()){
                if(kuang.size() == smax){
                    ans.push_back(kuang.top());
                    kuang.pop();
                }
                kuang.push(guidao[func-1].front());
                guidao[func-1].pop();
            }
        }
    }
    for(int i=0;i<ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}