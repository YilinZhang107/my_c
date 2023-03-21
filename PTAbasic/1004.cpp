#include<bits/stdc++.h>
using namespace std;

typedef struct stu{
    string name;
    string number;
    int grade;
}stu;

bool cmp(stu a, stu b){
    if(a.grade>b.grade)
        return 1;
    else 
        return 0;
}

int main(){
    int n;
    cin>>n;
    vector<stu> v;
    while(n--){
        stu t;
        cin>>t.name>>t.number>>t.grade;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    cout<<v[0].name<<" "<<v[0].number<<endl;
    cout<<v[v.size()-1].name<<" "<<v[v.size()-1].number<<endl;
    return 0;   
}