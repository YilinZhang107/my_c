/*
输入包括77行数据，分别表示周一到周日的日程安排。每行包括两个小于1010的非负整数
，用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。

一个数字。如果不会不高兴则输出00，如果会则输出最不高兴的是周几（用1, 2, 3, 4, 5, 6, 71,2,3,4,5,6,7分别表示周一，周二，周三
，周四，周五，周六，周日）。如果有两天或两天以上不高兴的程度相当，则输出时间最靠前的一天。

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int school,free;
    int i=1;
    int longestTime=0,unhappyDay=0;
    for(;i<=7;i++){
        cin >> school>>free;
        if((school+free)>longestTime&&(school+free)>8){
            longestTime = school+free;
            unhappyDay = i;
        }
    }
    cout<<unhappyDay;
    return 0;
}