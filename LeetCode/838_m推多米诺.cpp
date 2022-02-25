#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //自己的模拟法, 每一秒对现有的牌进行判断
    string pushDominoes(string dominoes) {
        //状态不再改变时,退出循环
        bool changed = true;
        int length = dominoes.length();
        //记录当前这一秒的情况,如果改变了不会再改变
        string oneSecond = dominoes;
        while(changed){
            changed = false;
            for(int i=0; i<length; i++){
                switch (dominoes[i])
                {
                case 'L':
                    if((i==1 && dominoes[i-1]=='.') || (i>1 && dominoes[i-1]=='.' && dominoes[i-2]!='R')){
                        oneSecond[i-1] = 'L';
                        changed = true;
                    }
                    
                    break;
                case 'R':
                    if((i==length-2 && dominoes[i+1]=='.') || (i<length-2 && dominoes[i+1]=='.' && dominoes[i+2]!='L')){
                        oneSecond[i+1] = 'R';
                        changed = true;
                    }
                    break;
                default:
                    break;
                }
            }
            dominoes = oneSecond;//将这1s的改变添加上去
        }
        return dominoes;
    }

    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, - 1);
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                q.emplace(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }

        string res(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                res[i] = f;
                int ni = (f == 'L') ? (i - 1) : (i + 1);
                if (ni >= 0 and ni < n) {
                    int t = time[i];
                    if (time[ni] == -1) {
                        q.emplace(ni);
                        time[ni] = t + 1;
                        force[ni].push_back(f);
                    } else if(time[ni] == t + 1) {
                        force[ni].push_back(f);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string dominoes = "RR.L";
    cout<<s.pushDominoes(dominoes);
    return 0;
}