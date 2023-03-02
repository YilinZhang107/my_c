#include<bits/stdc++.h>
using namespace std;

int main(){
    int v[105][105] ={0};
    int n,l1,l2,r1,r2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l1>>l2>>r1>>r2;
        for(int j=l1; j<r1;j++){
            for(int l = l2; l<r2; l++){
                v[j][l] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            if(v[i][j] )
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}