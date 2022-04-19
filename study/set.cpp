#include<bits/stdc++.h>
using namespace std;

struct myComp{//自定义比较函数
    bool operator()(const int &a,const int &b){//加const,不能改变set中的值
        return a>b;
    }
};

int main(){
    set<int> myset;
    myset.insert(1);
    myset.insert(5);
    myset.insert(4);
    for(int i:myset)
        cout<<i<<" ";  //会发现set有排序
    cout<<endl;

    //自定义的比较函数
    set<int,myComp> mycompset;
    mycompset.insert(1);
    mycompset.insert(5);
    mycompset.insert(4);
    for(int i:mycompset)
        cout<<i<<" ";  //会发现set有排序
    cout<<endl;


    return 0;
}

