#include<bits/stdc++.h>
using namespace std;
//md累死了
map<int, int> xingfu; 

int diedai(int n){
    int result= 0;
    while(n!=0){
        result += (n%10)*(n%10);
        n /=10;
    }
    return result;
}
int su(int n){
    for(int i=2;i<sqrt(n); i++){
        if(n%i == 0)
            return 0;        
    }
    return 1;
}

int duli(int n){
    set<int> death;
    int xing = 1 + 1*su(n);
    while(n != 1){
        death.insert(n);
        n = diedai(n);
        if(count(death.begin(), death.end(), n)){
            return 0;
        }
    }
    if(n==1){
        xing *= death.size();
        for(int t:death){
            if(xingfu.count(t))
                xingfu[t]++;
            else
                xingfu.insert(pair<int,int>(t,1));
        }
        return xing;
    }
    else{
        return 0;
    }
}

int main(){
    int head, back;
    cin>>head>>back;
    vector<int> dulixing(back-head+1);
    for(int i=head; i<=back; i++){
        dulixing[i-head] = duli(i);
    }
    int shuchu = 0;
    for(int i=head;i<=back; i++){
        if(xingfu[i] == 1){
            shuchu++;
            cout<<i<<' '<<dulixing[i-head]<<endl;
        }
    }
    if(!shuchu)
        cout<<"SAD";
    return 0;
}