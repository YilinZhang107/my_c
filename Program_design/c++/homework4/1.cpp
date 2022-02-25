#include<bits/stdc++.h>
using namespace std;

class Person{
    private:
        int number;//编号
        string name;//姓名

    public:
        Person(int num, string n){
            this->number = num;
            this->name = n;
        }
        void dataShow(){
            cout<<"number: "<<number<<", name: "<<name<<endl;
        }
};

class Student: public Person{
    private:
        int grade;
    public:
        Student(int num, string name, int g): Person(num,name), grade(g){}
        void Show(){
            dataShow();
            cout<<"grade: "<<grade<<endl;
        }
};

class Teacher: public Person{
    private:
        string title;
        string branch;
    public:
        Teacher(int num, string name, string t,string b):
             Person(num,name),title(t),branch(b){}
        void Show(){
            dataShow();
            cout<<"title: "<<title<<" , branch: "<<branch<<endl;
        }
};

int main(){
    Student *s1 = new Student(1, "zhang", 90);
    s1->Show();

    Teacher *t1 = new Teacher(2, "wang", "jiaoshou", "CS");
    t1->Show();
    return 0;
}