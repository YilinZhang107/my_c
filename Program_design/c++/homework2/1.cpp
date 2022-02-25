#include<bits/stdc++.h>
using namespace std;

class People{
    protected:
        int age;
        int height;
        int weight;
        static int num;

    public:
        People(int a, int h, int w){
            age = a;
            height = h;
            weight = w;
            num++;
        }

        void Eating(){
            weight++;
        }

        void Sporting(){
            height++;
        }

        void Sleeping(){
            age++;
            height++;
            weight++;
        }

        void Show(){
            cout<<"age="<<age<<endl;
            cout<<"height="<<height<<endl;
            cout<<"weight="<<weight<<endl;
        }

        static void showNum(){
            cout<<"num="<<num;
        }
};

int People::num = 0;
int main(){
    People zhang(0,0,0);
    zhang.Eating();
    zhang.Sporting();
    zhang.Sleeping();
    zhang.Show();
    zhang.showNum();
    return 0;    
}
