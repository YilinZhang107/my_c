//大数加减法,无准确题目
#include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> n1, vector<int> n2){
    int c = 0;//进位
    for(int i=n1.size()-1; i>=0; i--){
        int t = n1[i] + n2[i] +c;
        n1[i] = t%10;
        c = t/10;
    } 
    if(c) 
        n1.insert(n1.begin(), 1);
    return n1;
}

vector<int> sub(vector<int> n1, vector<int> n2){
    int fu = 0; //是否为负数
    for(int i=0; i<n1.size(); i++){
        if(n1[i] < n2[i]){
            vector<int> t = n2;
            n2 = n1;
            n1 = t;
            fu = 1;
            break;
        }
        else if(n1[i] > n2[i])
            break;
    }
    //"-"
    int jie = 0;
    for(int i=n1.size()-1; i>=0; i--){
        n1[i] -= jie;
        if(n1[i] - n2[i] < 0){
            jie = 1;
            n1[i] += 10;
        }
        n1[i] -= n2[i];
    }
    if(fu)
        cout<<"-";
    return n1;
}

int main(){
    string s1,s2, sym;
    cin>>s1>>sym>>s2;
    vector<int> n1,n2;
    if(s1.size() < s2.size()){//补0
        for(int i=0; i<s2.size()-s1.size() ; i++)
            n1.push_back(0);
    }
    else{
        for(int i=0; i<s1.size()-s2.size() ; i++)
            n2.push_back(0);
    }

    for(int i=0; i<s1.size(); i++){ //将字符各个位存入容器中
        n1.push_back(s1[i]-'0');
    }
    for(int i=0; i<s2.size(); i++)
        n2.push_back(s2[i]-'0');
    
    if(sym == "+")
        n1 = add(n1, n2);
    else    //"-"
        n1 = sub(n1, n2);

    int zero = 1;
    for(int i=0;i<n1.size(); i++){
        if(n1[i] ==0 && zero  && n1.size() != 1)
            continue;
        else{
            zero = 0;
            cout<<n1[i];
        }
    }

    
    return 0;
}