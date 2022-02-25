#include<iostream>
using namespace std;
                    
int main(){
    int x;
    cin >> x;
    if(x==0)
        cout<< "0 0 0 1";
    else{
        bool judge1 = (x%2==0),judge2 = (x>4&&x<=12);
    
        cout<< (judge1&&judge2);
        cout<< " "<< (judge1||judge2);
        cout<< " "<< ((judge1&&!judge2)||(!judge1&&judge2));
        cout<< " "<< (!judge1&&!judge2);
    }
    return 0;
}