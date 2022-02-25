#include<bits/stdc++.h>
using namespace std;

class cube{
    double length,width,height;
public:
    void setCube(){  //设置长宽高
        cin>>length>>width>>height;
    }

    double getVolume(){  //求体积
        double volume = length*width*height;
        return volume;
    }
};

int main(){
    cube c1,c2,c3;
    c1.setCube();
    c2.setCube();
    c3.setCube();
    cout<<"c1'volume = "<<c1.getVolume();
    cout<<"\nc2'volume = "<<c2.getVolume();
    cout<<"\nc3'volume = "<<c3.getVolume();
    return 0;
}