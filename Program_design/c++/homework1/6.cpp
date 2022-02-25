#include<bits/stdc++.h>
using namespace std;

class Circle{ //声明的circle类
public:
    double radius;  //半径
    double GetArea(){  //计算圆的面积
        double area = 3.14*radius*radius;
        return area;
    }
};

int main(){
    Circle *c1 = new Circle;  //构造一个圆对象
    cout<<"please set radius:";
    cin>>c1->radius;
    cout<<c1->GetArea();
    delete c1;
    return 0;
}