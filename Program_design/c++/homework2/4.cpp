#include<bits/stdc++.h>
using namespace std;

class Accout{
    private:
        int num;
        string name;
        string password;
        double balance;
        static double rate; //活期年利率
    public:
        Accout(int n,string nm,string p,double b){
            num = n;
            name = nm;
            password = p;
            balance = b;
        }
        void add(string p,double b){ //存款取款需要确认密码
            if (password == p)
                balance += b;
        }
        void reduce(string p,double b){ 
            if (password == p)
                balance -= b;
        }
        double claculate(){return balance*rate;}
        void showAccout(){
            cout<<"num="<<num<<endl;
            cout<<"name="<<name<<endl;
            cout<<"balance="<<balance<<endl;
        }
};

double Accout::rate = 0.05; //年利率5%

int main(){
    Accout *A = new Accout(1,"zhang","123",100);

    A->add("123", 5000); //存5000
    A->reduce("123",200); //取200
    A->showAccout();//查看账户情况
    cout<<"annual interest = "<<A->claculate()<<endl;

    delete A;
    return 0;
}