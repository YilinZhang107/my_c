#include<bits/stdc++.h>
using namespace std;

int main(){
    int day;
    cin>>day;
    int sum=0;
    int payday=0;
    int i=1; //发放的金币计数
    while(payday<day){
        for(int j=1; j<=i; j++){
            sum = sum + i;
            payday++;  //每天都要发工资
            if(payday>=day)
                break;
        }
        i++;
    }
    cout<<sum;
    return 0;
}