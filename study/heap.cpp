#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> dui = {3,2,4,5,76,5,3,7,8};
    //默认为less<>()大顶堆,这样是小顶堆
    make_heap(dui.begin(),dui.end(), greater<int>());
    for(int i=0;i<dui.size();i++){
        cout<<dui[i]<<" ";
    }
    cout<<endl;
    
    //在尾部添加一个树,并再次排序
    dui.push_back(10);
    push_heap(dui.begin(),dui.end(),greater<int>());
    for(int i=0;i<dui.size();i++){
        cout<<dui[i]<<" ";
    }
    cout<<endl;

    //取出顶端数,2被取到了数组末尾
    pop_heap(dui.begin(),dui.end(),greater<int>());
    for(int i=0;i<dui.size();i++){
        cout<<dui[i]<<" ";
    }
    cout<<endl;

    return 0;
}