#define vi vector<int> 
#include<bits/stdc++.h>
using namespace std;

int index[100][100] = {0};

int main(){
    int n, t, max = -1;
    cin>>n;
    vi many;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>max)   max= t;
        many.push_back(t);
        for(int j=0;j<t*10; j++){
            index[i][j] = 1;
        }
    }
    int ans = 1;
    for(int i=0;i<n;i++){
        for(int j=0; j<)
    }



    for(int i=0;i<n; i++){
        cout<<many[i];
    }
    return 0;
}