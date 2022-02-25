#include<bits/stdc++.h>
using namespace std;

//快速排序


void exch(int* n1, int* n2){
    int t = *n2;
    *n2 = *n1;
    *n1 = t;
}

int Partition(int* data, int length, int start, int end){
    if(data == nullptr || length <= 0 || start < 0 || end >= length){
        cerr<<"error"<<endl;
        return 0;    
    }

    int index = (rand()%(end-start+1)) + start; //取中间随机一个数字
    exch(&data[index], &data[end]);
    int small = start-1; //指向分界线
    for(index = start; index<end; index++){
        if(data[index] < data[end]){
            small++;
            if(small != index)
                exch(&data[small], &data[index]);
        }
    }
    small++;
    exch(&data[small], &data[end]);
    return small;
}


//递归实现
void QuickSort(int* data, int length, int start, int end){
    if(start == end)
        return;
    int index = Partition(data, length, start, end);
    if(index > start)
        QuickSort(data, length, start, index-1);
    if(index < end)
        QuickSort(data, length, index+1, end);
}

//=================test===============================
void Test1(){
    int a[10] = {1,5,3,34,43,234,4,10,234,9};
    QuickSort(a, 10, 0, 9);
    for(int i=0; i<10; i++)
        cout<<a[i]<<' ';
}

int main(){
    srand(time(0));
    Test1();
    return 0;
}