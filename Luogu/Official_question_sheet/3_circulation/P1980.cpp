#include<bits/stdc++.h>
#include <ctime>//看一下时间
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    const clock_t begin_time = clock();//开始计算
    
    int num=0;//计数
    int t;
    for(int i=1; i<=n; i++){
        t=i;
        while(t>=x){ //!!!这里把t>=x 改成t!=0之后就不超时了
            //但是用时钟测了时间发现>=好像更快....
            if(t%10==x)
                num++;
            t/=10;
        }
    }
    cout<<num<<endl;

    float seconds = float(clock()- begin_time)/1000;//返回处理时间，秒
    cout<<seconds;
    return 0;
}