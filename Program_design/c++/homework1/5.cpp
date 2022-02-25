#include<bits/stdc++.h>
using namespace std;

class Date{
    int day,month,year;

public:
    void setDate(){  //类内定义年月日的输入
        cin>>year>>month>>day;
    }

    void putDate();  
};  

void Date::putDate(){  //类外定义年月日的输出
    cout<<year<<' '<<month<<' '<<day;
}

int main(){
    Date d1;
    cout<<"输入年 月 日: ";
    d1.setDate();
    cout<<"\n输入的年月日是: ";
    d1.putDate();
    return 0;
}