/*给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。

original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。

请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组
*/
#include <bits/stdc++.h>
using namespace std;

//
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int> > newArray;
    if(m * n != original.size())
        return newArray;
    
    for(auto i=original.begin(); i!=original.end(); i+=n){
        newArray.emplace_back(i, i+n);//重点是这个方法
    }

    return newArray;
}


//my
vector<vector<int>> construct2DArray_1(vector<int>& original, int m, int n) {
    vector<vector<int> > newArray;
    if(m * n != original.size())
        return newArray;
    
    for(int i=0; i<m; i++){
        vector<int> *row = new vector<int>;
        for(int j=0; j<n; j++)
            row->push_back(original[i*n+j]);
        newArray.push_back(*row);
        delete row;
    }

    return newArray;
}

//==============test============
void Test(){
    vector<int> array {1,2,3,4};
    vector<vector<int>> newArray = construct2DArray(array, 2, 2);
    for(auto i=newArray.begin(); i!=newArray.end(); i++){
        for(auto j = i->begin(); j!=i->end(); j++)
            cout<<*j<<' ';
        cout<<endl;
    }
}

int main(){
    Test();

    return 0;
}