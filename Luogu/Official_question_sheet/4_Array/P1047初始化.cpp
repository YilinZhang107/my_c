#include<bits/stdc++.h>
using namespace std;

int main(){
    int longth, subway;
    cin>>longth>>subway;
    bool tree[longth+1] = {false};
    //memset(tree, true, sizeof(tree));有点麻烦了，直接用false代表有树

    for(int i=0; i<subway; i++){
        int start,end;
        cin>>start>>end;
        for(int i=start; i<=end; i++)
            tree[i]=true; //true代表没树
    }

    int sum=0;//树的数量
    for(int i=0; i<=longth; i++){
        if(!tree[i])
            sum++;
    }
    cout<<sum;
    return 0;

}