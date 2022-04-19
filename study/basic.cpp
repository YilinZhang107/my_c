#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;//简写

int main(){
    int n = 5;
    printf("%02d\n", n); //输出格式控制

    string s;
    cin>>n;
    getchar();//用完cin再用getline需要getchar一下
    getline(cin, s);
    cout<<s<<endl<<n<<endl;

    //s.find(), s.rfind()
    if(s.find("wo") != string::npos){//用这个表示没找到
        cout<<"return index "<<s.find("wo")<<endl;//返回的是第一个的下标
        cout<<"return from back first index: "<<s.rfind("wo")<<endl;//从后往前找第一个
    }
    //s.replace()
    s.replace(1, 2, "xxx");//(pos, len, xxx)
    cout<<s<<endl;
    s.replace(s.begin()+1, s.begin()+4, "hhh");
    cout<<s<<endl;

    //fill()  vector.max_element()
    vi temp(5);
    fill(temp.begin(), temp.end(), 9);//填充,可以作为初始化
    int max = *max_element(temp.begin(),temp.end());//注意这里返回itor
    cout<<"the *max_element: "<<max<<endl;

    return 0;
}