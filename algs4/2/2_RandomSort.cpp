//随机快速排序
#include<bits/stdc++.h>

using namespace std;

template<class T>
class quick{
    public:
        static void sort(T *t, int length){
            srand(unsigned(time(NULL)));//设置随机数种子
            //消除对数据的依赖
            random_shuffle(t,t+length);
            sort(t,0,length-1);
        }
    
    private:
        //将数组切分为a[lo..i-1],a[i],a[i+1..hi]
        static int partition(T *t,int lo,int hi){
            int i=lo, j=hi+1;//左右扫描指针
            T v = t[lo]; //切分元素
            while(true){
                //扫描左右,检查扫描是否结束并交换元素
                while(less(t[++i],v)) if (i==hi) break;
                while(less(v,t[--j])) if (j==lo) break;
                if(i>=j) break;
                exch(t,i,j);
            }
            exch(t,lo,j);
            return j;
        }

        static void sort(T *t,int lo, int hi){
            if(hi<=lo)
                return;
            int j = partition(t,lo,hi);//切分
            sort(t,lo,j-1);//左半排序
            sort(t,j+1,hi);//右边排序
        }
        static bool less(T &a, T &b){return a<b;}
        static void exch(T *t,int i, int j){
            T v = t[i];
            t[i] = t[j];
            t[j] = v;
        }
};

int main(){

    //quick<int>::sort(a,8);
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
    quick<int>::sort(a,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    quick<int>::sort(b,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    quick<int>::sort(c,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    quick<int>::sort(d,10000);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    return 0;
}