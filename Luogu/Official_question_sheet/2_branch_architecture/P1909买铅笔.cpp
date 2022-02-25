/*
P老师需要去商店买n支铅笔作为小朋友们参加NOIP的礼物。她发现商店一共有 33种包装的铅笔，不同包装内的铅笔数量有可能不同，价格也有可能不同。为了公平起 见，P老师决定只买同一种包装的铅笔。

商店不允许将铅笔的包装拆开，因此P老师可能需要购买超过nn支铅笔才够给小朋 友们发礼物。

现在P老师想知道，在商店每种包装的数量都足够的情况下，要买够至少nn支铅笔最少需要花费多少钱。
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int need;
    int n,count,he;
    int sum=0;
    cin>> need;
    for(int i=0;i<3;i++){
        cin>>n>>count;
        if(need%n==0&&need/n!=0)
            he = need/n;
        else if(need%n==0&&need/n==0)
            he = 1;
        else
            he = need/n+1;
        if(sum==0)
            sum = he*count;
        else if(he*count<sum)
            sum = he*count;
    }
    cout<<sum;
    return 0;
}