#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int half(int x){
    int l=0, r=v.size()-1, mid;
    while(l<r){
        mid = l + (r-l)/2;
        if(v[mid] >= x)
            r = mid;
        else
            l = mid+1;
    }
    if(v[l] != x)
        return -2;
    else
        return l;
}

int main(){
    vector<int> v;
    v.push_back(1);
    int ind = lower_bound(v.begin(), v.end(), 2)-v.begin();
    cout<<ind;
    v.insert(v.begin()+1,2);
    cout<<v[1];
    return 0;
}