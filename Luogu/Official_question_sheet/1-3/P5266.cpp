#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> mp;
    mp["li"]  = 1;
    mp["wang"] = 2;
    mp["chen"] = 3;
    for(map<string,int>::iterator i = mp.begin(); i!= mp.end(); i++){
        cout<<i->second<<endl;
    }
    return 0;
}