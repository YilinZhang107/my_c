#include<iostream>
using namespace std;
 
int main(){
    double t;
    int n;
    cin >> t >> n;
    
    cout.precision(3);   //控制小数位数，需要和fixed配合使用，表示小数位为3位
    cout << fixed << t/n << endl << n*2;
    //上两行可改为
    //cout<<setprecision(3)<<fixed<<t/n<<endl<<n*2
    return 0;
}