//自顶向下归并排序
#include<bits/stdc++.h>
using namespace std;

template<class A>
class TDMsort{
    private:
        A *aux;
        static bool less(A &a, A &b){
            return a<b;
        }
        //将a[lo,mid]和a[mid,hi]归并
        static void merge(A *a, int lo, int mid, int hi,A *aux){
            int i=lo, j = mid+1;
            //复制一遍到aux
            for(int k=lo; k<=hi; k++)
                aux[k] = a[k];
            //归并回到a[]
            for(int k=lo; k<=hi; k++){
                if(i>mid)                   //左半边用尽
                    a[k] = aux[j++];
                else if(j>hi)               //右半边用尽
                    a[k] = aux[i++];
                else if(less(aux[j],aux[i]))//右小于左
                    a[k] = aux[j++];
                else                        //左小于右
                    a[k] = aux[i++];
            }
        }
        //将数组a[lo..hi]排序
        static void sort(A *a, int lo, int hi, A *aux){
            if(hi<=lo)
                return;
            int mid = lo +(hi-lo)/2;
            sort(a,lo,mid,aux);//左半边排序
            sort(a,mid+1,hi,aux);//右半边排序
            merge(a,lo,mid,hi,aux);//归并结果
        }
   
    public:
        static void sort(A *a, int length){
            A *aux = new A[length];//准备好复制用的aux数组
            sort(a, 0, length-1,aux);
            delete[] aux;
        }
};

int main(){
    //TDMsort<int>::sort(a,8);
    
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
    TDMsort<int>::sort(a,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    TDMsort<int>::sort(b,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    TDMsort<int>::sort(c,87575);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    
    start = clock();
    TDMsort<int>::sort(d,10000);
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    

    return 0;
}