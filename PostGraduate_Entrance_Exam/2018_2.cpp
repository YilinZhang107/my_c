#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1 >> s2;
    int len1 = s1.size(), len2=s2.size() , lenc = len1, find = 0;
    string c;
    while( !find && lenc != 0){ // 从2中找1
        for(int i=0; i<s1.size()-lenc+1; i++){
            c = s1.substr(i,lenc);
            if(s2.find(c) != -1){
                find = 1;
                break;
            }
        }
        if(find == 0)
            lenc -= 1;
    }
    double ans = lenc*1.0/(len1+len2);
    cout<<fixed<<setprecision(2)<<ans<<endl;      //setprecision设置有效位数， 
    //printf("%.2f \n", ans);                        ///fixed控制小数点后位数(会补零)
    return 0;
}