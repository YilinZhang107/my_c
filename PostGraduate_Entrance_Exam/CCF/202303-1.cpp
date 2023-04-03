#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans[a][b];
    memset(ans, 0, sizeof(ans));

    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1 = x1<0 ? 0 : x1;
        y1 = y1<0 ? 0: y1;
        x2 = x2>a?a:x2;
        y2 = y2>b?b:y2;
        for(int j=x1; j<x2; j++){
            for(int l=y1; l<y2;l++){
                ans[j][l] = 1;
            }
        }
    
    }
    int sum = 0;
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(ans[i][j] == 1)
                sum++;
        }
    }
    cout<<sum<<endl;
    // for(int i=a-1; i>=0; i--){
    //     for(int j=0; j<b; j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}