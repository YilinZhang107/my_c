#include<bits/stdc++.h>
//#include<iomanip>
using namespace std;

double around(double x1, double y1,double x2, double y2, double x3,double y3){
    double c1,c2,c3;
    c1 = sqrt(abs((x1-x2)*(x1-x2))+abs((y1-y2)*(y1-y2)));
    c2 = sqrt(abs((x2-x3)*(x2-x3))+abs((y2-y3)*(y2-y3)));
    c3 = sqrt(abs((x3-x1)*(x3-x1))+abs((y3-y1)*(y3-y1)));
    return c1+c2+c3;        
}

int main(){
    double x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<fixed<<setprecision(2)<<around(x1,y1,x2,y2,x3,y3);
    return 0;
}
//注意保留两位小数