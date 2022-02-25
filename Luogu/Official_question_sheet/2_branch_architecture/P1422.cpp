#include<bits/stdc++.h>
using namespace std;

int main(){
    int du;
    cin>>du;
    cout<<setprecision(1)<<fixed;
    if(du<=150)
        cout<<du*0.4463;
    else if(du<=400)
        cout<<150*0.4463+(du-150)*0.4663;
    else
        cout<<150*0.4463+250*0.4663+(du-400)*0.5663;
    return 0;
}