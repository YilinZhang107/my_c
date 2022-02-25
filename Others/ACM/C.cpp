#include<bits/stdc++.h>
using namespace std;

int main(){
    int group;
    cin>>group;

    int times[group];

    for(int g=0; g<group; g++){
        int n, e1, e2,e3;
        cin>>n>>e1>>e2>>e3;
        long p[n] = {0};
        for(int i=0; i<n; i++)
            cin>>p[i];

        int max = e3/(e1-e2); //k<=max
        if(e3%(e1-e2)!=0)
            max++;

        int min = 999;
        for(int i=0; i<n-1; i++){
            long period =  p[i+1] - p[i];
            if(period-1<min)
                min = period-1;
        } //寻找最小间隔
        if(min>max)
            min = max;
        
        //计算不同k下最短时间
        int minTime = 0;
        for(int k=0; k<=max; k++){
            int time=0;
            for(int i=0; i<n; i++){
                if(i==0){//第一个人上电梯
                    time+=e3;
                    time+= (p[i]-0)*e2;
                    time+=e1;
                }
                else{
                    if((p[i]-p[i-1])-1 <= k){//间隔小于k
                        time+= (p[i]-p[i-1])*e1;
                    }
                    else{//间隔大于k
                        time+=e3;
                        time+=e1*(k+1);
                        time+= e2*(p[i]-(p[i-1]+k+1));
                    }
                }
            }
            if(minTime==0 || time<minTime)
                minTime = time;
        }
        times[g] = minTime;
    }
    for(int i=0; i<group; i++)
        cout<<times[i]<<endl;
    return 0;
}