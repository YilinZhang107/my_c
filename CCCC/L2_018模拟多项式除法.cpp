#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;
double a[100005],b[100005], c[100005];
//模拟多项式除法

void out(int max, double v[]){
    int sum = 0;
    for(int i=max; i>=0; i--){
        if(abs(v[i]) >= 0.05 ) sum++;
    }
    if(sum==0)  cout<<"0 0 0.0"<<endl;
    else{
        cout<<sum;
        for(int i=max; i>=0; i--){
            if(abs(v[i]) >= 0.05){
                printf(" %d %.1f",i,v[i]);
            }
        }
        cout<<endl;
    }
}

int main(){
    cin>>n;
    double x;
    int ma,mb,mc;
    memset(a,0.0,sizeof(a));
    memset(b,0.0,sizeof(b));
    memset(c,0.0,sizeof(c));
    for(int i=0;i<n;i++){
        cin>>m>>x;
        a[m] = x;
        if(i==0) ma = m;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>x;
        b[m] = x;
        if(i==0) mb = m;
    }
    mc = ma-mb;
    while(ma>=mb){
        double t = a[ma]/b[mb];//之后要四舍五入到点后一位
        c[ma-mb] = t;
        for(int i=ma,j=mb; i>=0,j>=0;i--,j--){
            a[i]-= t * b[j]; 
        } 
        while(!a[ma]) ma--;
    }   
    out(mc,c);
    out(ma,a);

    return 0;
}