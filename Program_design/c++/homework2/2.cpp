#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        char name[18];
        int num;
        int mathScore;
        int englishScore;
        static int count;
        static int mathTotalScore;
        static int englishTotalScore;

    public:
        Student(char *nm,int nu,int math, int english){
            for (int i=0;i<18;i++){
                if (nm[i] == '\000')
                    break;    
                name[i] = nm[i];
            }
            num = nu;
            mathScore = math;
            englishScore = english;
            count++;
            mathTotalScore += math;
            englishTotalScore += english;
        }
        void ShowBase(){
            cout<<"name="<<name<<endl;
            cout<<"num="<<num<<endl;
            cout<<"mathscore="<<mathScore<<endl;
            cout<<"englishscore="<<englishScore<<endl;
        }
        static void showStatic(){
            cout<<"count="<<count<<endl;
            cout<<"mathTotalScore="<<mathTotalScore<<endl;
            cout<<"englishTotalsScore="<<englishTotalScore<<endl;
        }
};

int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;

int main(){
    Student A("zhang",1,90,60);
    A.ShowBase();
    A.showStatic();
    cout<<endl;
    Student B("li",2,89,80);
    B.ShowBase();
    B.showStatic();
    cout<<endl;
    Student C("zhao",3,60,70);
    C.ShowBase();
    C.showStatic();
  
    return 0;
}
