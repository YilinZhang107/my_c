#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;

    while(n!= 0){
        int x=1,y=1;//对（1，0）进行变换
        int x1 = 0, y1 = 0;
        x1 = (x+y)%n;
        y1 = (x+y*2)%n;
        int i;
        for(i=1;x!=x1|| y != y1;i++){
            int t = (x1+y1)%n;
            y1 = (x1+y1*2)%n;
            x1 = t;
        }
        v.push_back(i);
        cin>>n;
    }
    for(int i=0;i<v.size(); i++)
        cout<<v[i]<<endl;
    return 0;
}