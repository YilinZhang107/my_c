#include<bits/stdc++.h>
using namespace std;

// 对角线个数：=n*（n-3）/2
// 对角线交点个数：=C^4(下标是n)
// 即在此多边形中有多少个四边形（任取四个点）
int main(){
    unsigned long long n;
    cin>>n;
    
    unsigned long long num = n*(n-1)/2*(n-2)/3*(n-3)/4;
    cout<<num;
    return 0;   
}
// 本题重点在于使用unsigned long long(如果不想写高精度的话)