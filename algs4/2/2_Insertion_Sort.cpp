//插入排序
#include<bits/stdc++.h>
#include<time.h>
using namespace std;

template<class A>
class Insertion_sort {
    private:
        static bool less(A &a, A &b){
            return a<b;
        }
    public:
        static void sort(A *a, int length){
            for(int i=1; i<length; i++){
                int j;
                A t = a[i];
                for(j=i; j>0 && less(t,a[j-1]); j--){//前一位小于a[i]
                    a[j] = a[j-1];//右移一位而不是交换
                }
                a[j] = t; //将a[i]移动到最小位置上
            }
        }
};

void insert_sirt(int *t, int length){
    Insertion_sort<int>::sort(t,length);
}

int main(){
    ifstream infile;
    infile.open("D://Codes/C/text.txt",ios::in);
    int t;
    int a[87575];
    int b[87575];
    int c[87575];
    int d[10000];
    for(int i=0; i<87575; i++){
        infile>>t;
        a[i] = t;
        infile>>t;
        b[i] = t;
        infile>>t;
    }
    srand(unsigned(time(NULL)));//设置随机数种子
    for(int i=0; i<87575; i++){
        c[i] = rand();
    }
    for(int i=0; i<10000; i++){
        d[i] = rand();
    }

    clock_t start, end;//记录时间
    start = clock();
    insert_sirt(a, 87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    insert_sirt(b, 87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    insert_sirt(c, 87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    insert_sirt(d, 10000);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    

    return 0;
}