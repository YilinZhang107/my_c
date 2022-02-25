#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    char c[num][101];
    for(int i=0; i<num; i++)
        cin>>c[i];

    for(int i=0; i<num ;i++){
        int l=1;
        int j=0;
        for(l=1; l<101; l++){
            bool allZero = false;
            
            for(j; j<strlen(c[i]); j++){
                if(c[i][j]=='1' && c[i][j+1]=='0'){
                    c[i][j]='0';
                    j++;
                    break;
                }
                else if(c[i][j]=='1' && c[i][j+1]=='1'){
                    c[i][j]='0';
                    
                    continue;
                }
                else if(c[i][j]=='1' && j==strlen(c[i])-1){
                    c[i][j]='0';
                    allZero = true;
                    break;
                }
                if(j==strlen(c[i])-1){
                    l--;
                    allZero = true;
                }
            }
            if(allZero)
                break;
        }
        cout<<l<<endl;
    }

    
    return 0;
}