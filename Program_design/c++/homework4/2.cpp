#include<bits/stdc++.h>
using namespace std;

class Teacher{
    protected:
        string name;
        int age;
        string sex;
        string address;
        string phoneNumber;
        string title;
    public:
        Teacher(string n,int ag,string s,string add,string pN,string t);
        void display();
};

Teacher::Teacher(string n,int ag,string s,string add,string pN,string t):
    name(n),age(ag),sex(s),address(add),phoneNumber(pN),title(t){}

void Teacher::display(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"sex: "<<sex<<endl;
    cout<<"address: "<<address<<endl;
    cout<<"phoneNumber: "<<phoneNumber<<endl;
}

class Cadre{
    protected:
        string name;
        int age;
        string sex;
        string address;
        string phoneNumber;
        string post;
    public:
        Cadre(string n,int ag,string s,string add,string pN,string p);
        void display();
};

Cadre::Cadre(string n,int ag,string s,string add,string pN,string p):
    name(n),age(ag),sex(s),address(add),phoneNumber(pN),post(p){}

void Cadre::display(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"sex: "<<sex<<endl;
    cout<<"address: "<<address<<endl;
    cout<<"phoneNumber: "<<phoneNumber<<endl;
}

class Teacher_Cadre: public Teacher,public Cadre{
    private:
        int wages;
    
    public:
        Teacher_Cadre(string n,int ag,string s,string add,string pN,string t,string p,int w);
        void Show();
};

Teacher_Cadre::Teacher_Cadre(string n,int ag,string s,string add,string pN,string t,string p,int w)
    :Teacher(n,ag,s,add,pN,t),Cadre(n,ag,s,add,pN,p),wages(w){}
    
void Teacher_Cadre::Show(){
    Teacher::display();
    cout<<"post: "<<Cadre::post<<endl;
    cout<<"wages: "<<wages<<endl;
}

int main(){
    /*
    Teacher *t1 = new Teacher("zhang",10,"man","xian","152","professor");
    t1->display();

    Cadre *c1 = new Cadre("zhang",10,"man","xian","152","professor");
    c1->display();
    */
    Teacher_Cadre *TC1 = new Teacher_Cadre("zhang",30,"man","xi'an","610001","professor","zhu ren",8000);
    TC1->Show();

    return 0; 
}