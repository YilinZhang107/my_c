#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];

    sort(a, a+3);
/*此处格局小了，直接从大到小算最大公约数即可   
    while(true){
        int pan=0;//判断此次是否约分了
        for(int i=2; i<a[0]; i++){
            if(a[0]%i==0 && a[2]%i==0){
                pan++;
                a[0]/=i;
                a[2]/=i;
                break;
            }
        }
        if(pan==0)  //没约分就直接退出
            break;
    }
*/
    for(int i = a[0]; i>1; i--){
        if(a[0]%i==0 && a[2]%i==0){
            a[0]/=i;
            a[2]/=i;
            break;
        }
    }
    cout<<a[0]<<"/"<<a[2];
    return 0;
}