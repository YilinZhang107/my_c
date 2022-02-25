#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout<<"I love Luogu!";
        break;
    case 2:
        cout<<2+4<<" "<<10-2-4;
        break;
    case 3:
        cout<<14/4<<endl<<(14/4)*4<<endl<<14-(14/4)*4;
        break;
    case 4:
        cout<<500.0/3;
        break;
    case 5:
        cout<<15;
        break;
    case 6:
        cout<<sqrt(6*6+9*9);
        break;
    case 7:
        cout<<"110"<<endl<<"90"<<endl<<"0";
        break;
    case 8:{
        int r = 5;
        double pi = 3.141593;
        cout<<2*pi*r<<endl<<pi*r*r<<endl<<4*pi*r*r*r/3;
        break;
    }
    case 9:
        cout<<((((1+1)*2+1)*2+1)*2);
        break;
    case 10:
        cout<<"9";
        break;
    case 11:
        cout<<100.0/(8-5);
        break;
    case 12:
        cout<<13<<endl<<"R";
        break;
    case 13:{
        double pi = 3.141593;
        double total = 4*pi*4*4*4/3+4*pi*10*10*10/3;
        cout<<int(pow(total,1.0/3));
        break;
    }
    case 14:
        cout<<"50";
        break;
    
    }
}