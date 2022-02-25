#include<bits/stdc++.h>
#include<stack>
using namespace std;
/*暴力解法
int main(){
    int n,i;
    cin>>n;
    int cun[200];
    for(i=0; i<200; i++){
        cun[i]=n;
        if(n==1)
            break;
        else if(n%2!=0)
            n = n*3+1;
        else
            n = n/2;
    }
    for(;i>=0;i--)
        cout<<cun[i]<<" ";
    return 0;
} 
*/

/*/递归解法
void pan(int x){
    if(x==1){
        cout<<"1 ";
        return;
    }
    else if(x%2!=0)
        pan(x*3+1);
    else
        pan(x/2);
    cout<<x<<" ";
    return;
}

int main(){
    int n;
    cin>>n;
    pan(n);
    return 0;
}
*/

//用栈(stack)实现
stack<int> s;

int main(){
    int n;
    cin>>n;
    while(n!=1){
        s.push(n);
        if(n%2==0)
            n /= 2;
        else
            n = n*3+1;
    }   
    s.push(1);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}