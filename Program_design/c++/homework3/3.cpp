#include<bits/stdc++.h>
using namespace std;

class cube{
    private:
        int value[2][3];
    public:
        friend istream & operator>>(istream &is, cube &c){
            cout<<"please input 6 numbers: ";
            for(int i=0;i<2;i++){
                for(int j=0; j<3;j++)
                    is>>c.value[i][j];
            }
            return is;
        }
        friend ostream & operator<<(ostream &os, cube &c){
            for(int i=0;i<2;i++){
                for(int j=0; j<3;j++)
                    os<<c.value[i][j]<<' ';
                os<<endl;
            }
            return os;
        }
};

int main(){
    cube c1,c2;
    cin>>c1;
    cin>>c2;

    cout<<c1<<c2;
    return 0;
}