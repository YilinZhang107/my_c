#include<bits/stdc++.h>
using namespace std;

class Dog{
    private:
        char *name; //用字符指针描述name
        int age;
        bool sex;
        int weight;
    
    public:
        Dog(char *n, int a, bool s, int w){
            name = n;
            age = a;
            sex = s;
            weight = w;
        }
        void show(){  //打印全部属性的方法
            cout<<"name="<<name<<endl;
            cout<<"age="<<age<<endl;
            cout<<"sex="<<sex<<endl;
            cout<<"weight="<<weight<<endl;
        }
};

int main(){
    char nameA[] = "haha";
    char *n = nameA;
    
    Dog *a = new Dog(n,10,true,50); //对象指针

    a->show(); //测试
    delete a;
    return 0;
}