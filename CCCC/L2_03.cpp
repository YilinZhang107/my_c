#include<bits/stdc++.h>
using namespace std;
int n,d,i,j;
int main(){
    cin>>n>>d;
    vector<double> avg;
    double t2,t1;
    vector<double> stock;
    int sum = 0;
    for(i=0;i<n;i++){
        cin>>t1;
        stock.push_back(t1);
        sum+=t1;
    }
    for(i=0;i<n;i++){
        cin>>t2;
        avg.push_back((t2*1.0)/(stock[i]*1.0));
    }
    double ans=0.0;
    if(sum<=d){
        for(i=0;i<n;i++){
            ans+=stock[i]*avg[i];
        }
        printf("%.2f",ans);
        return 0;
    }
    while(d!=0){
        int max=-1,ind;
        ind = max_element(avg.begin(),avg.end())-avg.begin();
        if(stock[ind] > d){
            ans+=(d*avg[ind]);
            break;
        }
        else{
            d -= stock[ind];
            ans+=avg[ind]*stock[ind];
            stock.erase(stock.begin()+ind);
            avg.erase(avg.begin()+ind);
        }
    }
    printf("%.2f", ans);
    return 0;
}