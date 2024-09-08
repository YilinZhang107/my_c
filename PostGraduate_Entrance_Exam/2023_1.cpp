// 成绩加权

#include <bits/stdc++.h>
using namespace std;

struct Student{
    int id;
    int score[4];
    int sumScore = 0;
    double weightScore = 0;
};

bool cmp(Student a, Student b){
    if(a.weightScore != b.weightScore)
        return a.weightScore > b.weightScore;

    if(a.sumScore != b.sumScore)
        return a.sumScore > b.sumScore; 
    
    return a.id < b.id;
}

int main(){
    vector<Student> students;
    double weights[4] = {0.35, 0.3, 0.2, 0.15};
    int n;

    cin>>n;
    for(int i=0; i<n; i++){
        Student s;
        cin>>s.id;
        for(int j=0; j<4; j++){
            cin>>s.score[j];
            s.sumScore += s.score[j];
        }
        sort(s.score, s.score+3, greater<int>());
        for(int j=0; j<4; j++)
            s.weightScore += s.score[j]*weights[j];
        students.push_back(s);
    }
    sort(students.begin(), students.end(), cmp);

    for(int i=0; i<n; i++)
        cout<<students[i].id<<endl;
    
    return 0;
}
