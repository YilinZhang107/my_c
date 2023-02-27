#include<bits/stdc++.h>
using namespace std;
                     //注意最大因子的算法
int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n;i++){
        string t;
        cin>>t;
        vector<int> num;
        for(int j=0;j<t.size(); j++){
            if(t[j]>='0' && t[j]<='9'){
                num.push_back(t[j]-'0');
            }
        }
        if(num.empty())
            v.push_back(0);
        else{
            int ans=0,cheng=1;
            for(int j=num.size()-1; j>=0; j--){
                ans += num[j]*cheng;
                cheng *= 10;
            }
            int j;
            for(j=ans/2; j>=1; j--){
                if(ans%j==0){
                    v.push_back(j);
                    break;
                }
            }
        }
    }
    for(int i=0;i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    return 0;
}