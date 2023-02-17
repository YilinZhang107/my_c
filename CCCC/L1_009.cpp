#include<bits/stdc++.h>
using namespace std;
long long zi[105],mu[105],fu[105];
long long ans=0;
int main(){
    int n;
    cin>>n;
    vector<int> vi;
    string s;
    memset(fu,0,sizeof(fu));
    int sum = 1;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0] == '-'){
            fu[i] = -1;
            s = s.substr(1,s.size()-1);
        }
        else
            fu[i] = 1;
//         cout<<s<<endl;
        int pos = s.find('/');
//         cout<<pos<<endl;
        zi[i] = stol(s.substr(0,pos));
        mu[i] = stol(s.substr(pos+1,s.size()-pos-1));
//         cout<<zi[i]<<" "<<mu[i]<<endl;
        sum *=mu[i];
    }
    for(int i=0;i<n;i++){
//         cout<<mu[i]<<" "<<zi[i]<<" "<<fu[i]<<endl;
        int t = sum/mu[i];
        zi[i]*=t;
        ans+=zi[i] * fu[i];
    }
    int ansf = 1;
    if(ans<0)
    {
        ansf = -1;
        ans*=-1;
    }   
    int zheng = 0;
    if(ans>=sum)
        zheng = ans/sum;
    // cout<<zheng<<" ";
    ans%=sum;
    // cout<<ans<<" ";
    for(int i=2;i<=ans;i++){
        // cout<<sum%i<<""<<ans%i<<endl;
        if(sum%i==0 && ans%i==0){
            sum /=i;
            ans/=i;
            i=2;
        }
    }
    if(zheng == 0 && ans ==0){
        cout<<0;
        
    }else if(ans == 0){
        cout<<zheng;
    }else if(zheng ==0)
        cout<<ans*ansf<<"/"<<sum;

    else{
        cout<<zheng<<" "<<ans*ansf<<"/"<<sum;
    }
}