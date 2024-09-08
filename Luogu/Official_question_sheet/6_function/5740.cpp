#include<bits/stdc++.h>
using namespace std;



struct student{
    string name;
    int yu;
    int math;
    int eng;
    int sum;

    // bool compare < (const student &b){
    //         return sum < b.sum;
    // }
};

// bool cmp(student a, student b){
//     return a.sum>b.sum;
// }

int main(){
    int n, i;
    cin>>n;
    cin>>n;
    student maxStu;
    for (i=0; i<n; i++){
        student t;
        cin>>t.name>>t.yu>>t.math>>t.eng;
        t.sum = t.yu+t.math+t.eng;
        if(i==0)
            maxStu = t;
        else{
            if (maxStu.sum < t.sum)
                maxStu = t;
        }
    }
    cout<<maxStu.name<<" "<<maxStu.yu<<" "<<maxStu.math<<" "<<maxStu.eng;
}
 
