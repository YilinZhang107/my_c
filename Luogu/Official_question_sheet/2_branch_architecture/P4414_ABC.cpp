#include<bits/stdc++.h>
using namespace std;

int main(){
    int num[3];
    for(int i=0;i<3;i++){
        cin>>num[i];
    }
    sort(num, num+3);
    char c;
    for(int i=0;i<3;i++){
        cin>>c;
        switch (c)
        {
        case 'A':
            cout<<num[0]<<" ";
            break;
        
        case 'B':
            cout<<num[1]<<" ";
            break;

        case 'C':
            cout<<num[2]<<" ";
            break;
        default:
            break;
        }
    }
    return 0;
}