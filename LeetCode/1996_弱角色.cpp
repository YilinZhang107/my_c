#include<bits/stdc++.h>
using namespace std;

//难点在于排序方法,atk按升序,def按降序


//这个函数要定义在类外
//自定义的排序规则, 攻击力按升序排序, 攻击力相同时以降序排序
//这样需要从后往前遍历, 为了方便我们再倒过来
bool cmp(vector<int> a, vector<int> b){
        //return a[0]==b[0] ? (a[1]>b[1]) : (a[0]<b[0]);
        return a[0]==b[0] ? (a[1]<b[1]) : (a[0]>b[0]);
    }

class Solution {
public:
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
    //lambda表达式写法
    //     sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int>& b){
    //     //return a[0]==b[0] ? (a[1]>b[1]) : (a[0]<b[0]);
    //     return a[0]==b[0] ? (a[1]<b[1]) : (a[0]>b[0]);
    // });
        sort(properties.begin(), properties.end(), cmp);
        int num=0;
        int maxDEF = -1;
        for(auto i = properties.begin(); i != properties.end(); i++){
            if((*i)[1] < maxDEF)
                num++;
            else
                maxDEF = (*i)[1];
        }
        return num;
    }
};

int main(){
    vector<vector<int>> nums= {{1,2},{2,3}};
    Solution s;
    cout<<s.numberOfWeakCharacters(nums);
    return 0;
}