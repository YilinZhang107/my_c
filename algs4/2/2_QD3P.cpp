//Dijkstra 3路划分快速排序
#include<bits/stdc++.h>
using namespace std;

template<class T>
class quick3way{
    public:
        static void sort(T *t, int length){
            srand(unsigned(time(NULL)));//设置随机数种子
            //消除对数据的依赖
            random_shuffle(t,t+length);
            sort(t,0,length-1);
        }
    
    private:
            static void sort(T *t,int lo, int hi){
            if(hi<=lo) return;
            int lt = lo, i = lo+1, gt = hi;
            T v = t[lo];
            while(i<=gt){
                if (t[i] < v) exch(t, lt++, i++);
                else if(t[i] > v) exch(t,i, gt--);
                else i++;
            }//现在a[lo..lt-1]<v = a[lt..gt] < a[gt+1..hi]成立
            sort(t,lo, lt-1);
            sort(t,gt+1,hi);
        }

        static void exch(T *t,int i, int j){
            T v = t[i];
            t[i] = t[j];
            t[j] = v;
        }
};

int main(){
   
    //quick3way<int>::sort(a,8);
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
    quick3way<int>::sort(a,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    quick3way<int>::sort(b,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    quick3way<int>::sort(c,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    quick3way<int>::sort(d,10000);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    return 0;
}