#include<iostream>
using namespace std;

int main(){            //其实可以只反转一半数字，全部反转很容易越界
    int x;
    cin>> x;

    if(x<0)
        cout<<"不是回文数"<<endl;
    else if(x==0)
        cout<<"是回文数"<<endl;
    else{
        int i,copy;
        copy = x;
        for( i=1; i>0; i++){
            copy = copy/10;
            if(copy==0)
                break;
        }
        long long y=0;
        copy=x;
        for(int j=0;j<i;j++){
            y = y*10;
            y = y+(copy%10);
            copy=copy/10;
        }
        if(x==y)
            cout<<"是回文数"<<endl;
        else
            cout<<"不是回文数"<<endl; 
    }
    return 0;
}