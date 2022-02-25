#include<bits/stdc++.h>
using namespace std;

class Date{
    private:
        int year;
        int month;
        int day;
    
    public:
        Date(int y, int m, int d){
            year = y;
            month = m;
            day = d;
        }    
        friend class Time;
};

class Time{
    private:
        int hour;
        int min;
        int second;
    public:
        Time(int h, int m, int s){
            hour = h;
            min = m;
            second = s;
        }
        void display(Date &d){//注意先后顺序,要先定义作为参数的类
            cout<<d.year<<'-'<<d.month<<'-'<<d.day<<' ';
            cout<<hour<<':'<<min<<':'<<second<<endl;
        }
};

int main(){
    Date d(2021,11,5);
    Time t(11,32,55);
    t.display(d);
    return 0;
}