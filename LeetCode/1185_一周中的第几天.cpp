#include<bits/stdc++.h>
using namespace std;
/*
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

*/

//1971年1月1日 星期5
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        const string week[] = {  "Thursday","Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday"};
        const int days[]  = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        int pastDays = (year-1971)*365+day;
        for(int i=0;i<month;i++)
            pastDays += days[i];
        //加上闰年多的1天
        for(int i = 0; i<year-1970; i++){
            if((year-i)%400 == 0 || ((year-i)%4 == 0 && (year-i)%100 != 0)){
                if(!(i == 0 && month<=2))
                    pastDays ++;
            }
        }
        return week[pastDays%7];
    }
};

//=============test===========
int main(){
    Solution *test  = new Solution();
    cout<<test->dayOfTheWeek(29,2,2016);

    return 0;
}