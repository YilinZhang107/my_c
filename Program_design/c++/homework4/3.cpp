#include<bits/stdc++.h>
using namespace std;

class Shape{//抽象类
    public:
        virtual double acreage() = 0;//纯虚函数
};

class Circle:public Shape{
    private:
        double radius;
    public:
        Circle(double R):radius(R){}
        double acreage(){ return 3.14*radius*radius;}
};

class Square:public Shape{
    private:
        double length;
    public:
        Square(double l):length(l){}
        double acreage(){return length*length;}
};

//长方形
class Rectangle:public Shape{
    private:
        double xlength;
        double ylength;
    public:
        Rectangle(double x,double y):xlength(x),ylength(y){}
        double acreage(){return xlength*ylength;}
};

//梯形
class Trapezoid:public Shape{
    private:
        double hlength;
        double llenght;
        double highth;
    public:
        Trapezoid(double hl,double ll, double ht):hlength(hl),llenght(ll),highth(ht){}
        double acreage(){return (hlength+llenght)*highth/2;}
};

class Triangle:public Shape{
    private:
        double llength;
        double heigth;
    public:
        Triangle(double l,double h):llength(l),heigth(h){}
        double acreage(){
            return llength*heigth/2;
        }
};

int main(){
    Shape* s[5] = { new Circle(5),
                    new Square(5),
                    new Rectangle(3,4),
                    new Trapezoid(4,6,2),
                    new Triangle(5,4)
                };
    
    double sum =0;
    for(int i=0;i<5;i++){
        cout<<s[i]->acreage()<<" ";
        sum += s[i]->acreage();
    
    }
    cout<<endl<<sum<<endl;

    return 0;
}