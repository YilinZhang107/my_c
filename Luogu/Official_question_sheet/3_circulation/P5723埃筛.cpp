#include<bits/stdc++.h>
using namespace std;

bool prime[100000]; //埃氏筛法,先定义数组

void ai(){
    memset(prime, true, sizeof(prime)); //假定所有数都为质数
    for(int i=2; i<100000; i++){
        if(prime[i]){
            for(int j=i*2; j<100000 ;j+=i) //核心：如果nn是质数，
                prime[j]=false; //那么2n,3n,4n,这些nn的倍数肯定都不是质数。
        }
    }
}

int main(){
    int max;
    cin>>max;
    int sum=0;
    int i=2;
    int num=0;
    
    ai();//筛质数
    for(i; ;i++){
        if(prime[i]){
            sum += i;
            if(sum>max)
                break;
            cout<<i<<endl;
            num++;
        }
    }

    /*
    while(true){
        bool zhi = true;         //判断是否是质数
        for(int j=2; j<i; j++){
            if(i%j==0){
                zhi = false;
                break;
            }
        }
        if(zhi){
            sum += i;
            if(sum>max)
                break;
            cout<<i<<endl;
            num++;
        }
        i++;
    }
    */
    cout<<num<<endl;
    return 0;
}