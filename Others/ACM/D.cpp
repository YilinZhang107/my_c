#include<bits/stdc++.h>
using namespace std;

int main(){
    int day;
    cin>>day;
    int increase[day];

    int sums[day] = {0};
    
    int starts[day] = {0};
    int start = 0;
    int ends[day] = {0};
    int end = 0;
    
    int p = 0;

    for(int i=0; i<day; i++){
        cin>>increase[i];
        if(increase[i]>=0){
            if(i==0 || increase[i-1]<0){
                starts[p] = i;
            }
            sums[p] += increase[i];
        }
        else{
            if(i != 0)
                end[p] = i;
        } 
    }
    
}