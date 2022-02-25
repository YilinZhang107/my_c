#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int number;
        int score;

    public:
        Student(int n=0, int s=0){
            number = n;
            score = s;
        }
        int getNumber(){
            return number;
        }
        int getScore(){
            return score;
        }
        void getMessage(){
            cout<<number<<" "<<score<<endl;
        }

};

void Max(Student *s){
    int max = s->getScore();
    int n = 0;
    for(int i=1; i<5;i++){
        if(max<(s+i)->getScore()){
            max = (s+i)->getScore();
            n = i;
        }
    }
    cout<<"the highest number is: "<<(s+n)->getNumber();
}

int main(){
    Student classroom[5] = {
        Student(1,90),
        Student(2,80),
        Student(3,60),
        Student(4,99),
        Student(5,97)
    };
    Student *s = classroom;

    s[0].getMessage();
    (s+2)->getMessage();
    s[4].getMessage();
    Max(s);

    return 0;
}