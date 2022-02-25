#include<bits/stdc++.h>
using namespace std;

class empty{

};
class empty_1{
    public:
        empty_1(){}
        virtual ~empty_1(){}
        virtual void base(){}
};

class A{
private:
    int value;
public:
    A(int n):value(n){}
    //A(A other){  //不允许复制构造函数传值参数, 需要改为常量引用
    A(const A &other){
        value = other.value;
    }
    void print(){cout<<value<<endl;}
};

int main(){
    cout<<sizeof(empty)<<endl;//空类的大小为1个字节,必须占有一定空间,否则无法使用实例
    empty e;
    cout<<sizeof(e)<<endl;
    empty_1 e1;
    cout<<sizeof(e1)<<endl;//多一个指向虚函数表的指针,指针大小64位为8字节
    
    A a = 10;
    A b = a;
    b.print();
    
    
    return 0;
}