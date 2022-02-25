#include<bits/stdc++.h>
#include<time.h>
using namespace std;
//改进过的加权quick-union算法(指把vector换成了数组,确实快了一些)

class site{
    private:
        int number=0;  //序号,在矩阵中的位置:n=i*n+j
        bool isblocked=true;  //是不是黑
        bool isfull=false;  //是不是被填充
        
    public:
        int id=0;    //索引
        int sz=1;    //(由触电索引的)各个根节点所对应的分量的大小
        site(int n,bool iB=true,bool iF=false):number(n),id(n),isblocked(iB),isfull(iF) {}
        site(){}
        void open(){
            isblocked = false;
        }
        void full(){
            if (!isblocked)
                isfull = true;
            else
                cout<<"this site is blocked!"<<endl;
        }
        bool isOpen(){
            return !isblocked;
        }
        bool isFull(){
            return isfull;
        }
};

//加权quick-union算法
class quickUnion{
    public:
        static int find(site *s, int p){ //p = i*n+j
            while(p != s[p].id)
                p = s[p].id;
            return p;
        }
        //归并到同一个分量中
        static void myunion(site *s, int p, int q){
            int i = find(s,p);
            int j = find(s,q);
            if(i == j) return;//如果已经在同一个分量中不改变
            //把小树的根节点连接到大树的根节点
            if(s[i].sz<s[j].sz){
                s[i].id = j;
                s[j].sz += s[i].sz;
            }
            else{
                s[j].id = i;
                s[i].sz += s[j].sz;
            }
        }
};

class Percolation {
    private:
         
        int n;  //大小
        site *sites;  //site数组
        bool percolate = false;
        double t = 0;  //渗透时所进行的操作次数

    public:
        Percolation(int N){ // create N-by-N grid, with all sites blocked
            n = N;
            sites = new site[n*n+1]();
            for(int i=0; i < n; i++){
                for(int j=0; j< n; j++){
                    sites[i*n+j] = site(i*n+j);
                }
            }
            sites[n*n] = site(n*n);//这是一个虚顶点, 作为"源头"?所有第一行和此点union                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        }
        ~Percolation(){ // create N-by-N grid, with all sites blocked
            delete sites;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
        }
        
        void open(int i, int j){ // open site (row i, column j) if it is not already
            sites[i*n+j].open();
        }
        
        bool isOpen(int i, int j){ // is site (row i, column j) open?
            return sites[i*n+j].isOpen();
        }
        
        bool isFull(int i, int j){ // is site (row i, column j) full?
            return sites[i*n+j].isFull();
        }  

        bool percolates(){ // does the system percolate?是否渗透
            return percolate;
        }  
        
        void showSites(){
            for(int i = 0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(!sites[i*n+j].isOpen()) //blocked
                        cout<<"="<<"  ";
                    else if(sites[i*n+j].isFull())   //full
                        cout<<"@"<<"  ";
                    else                          //open
                        cout<<"O"<<"  ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        //遍历一遍进行渗透,和第一行的site在同一个分量对它进行填充
        //取出便于下面方法调试
        void per(){
            for(int i=0; i<n*n;i++){
                if(quickUnion::find(sites,i) == quickUnion::find(sites,n*n) && sites[i].isOpen()) 
                    sites[i].full();
            }
        }

        double simulation(){ // test onces
            
            while(!percolate){
                int r = rand()%(n*n);
                //是否已经打开
                if(sites[r].isOpen())
                    continue;
                else{
                    sites[r].open();
                    //第一行被open后,自动和虚顶点连接
                    if(r<n){
                        quickUnion::myunion(sites,n*n,r);
                    }
                    t++;//计数
                }

                //以上左右下的顺序,与周围的site进行union, id定为最小的
                if(r>=n && sites[r-n].isOpen()) //与上方union,排除第一行
                    quickUnion::myunion(sites, r, r-n);
                if(r%n!=0 && sites[r-1].isOpen()) //与左union, 排除第一列
                    quickUnion::myunion(sites, r, r-1);
                if((r+1)%n!=0 && sites[r+1].isOpen()) //与右union, 排除第n列
                    quickUnion::myunion(sites, r, r+1);
                if((r+n)<n*n && sites[r+n].isOpen()) //与下union, 排除第n行
                    quickUnion::myunion(sites, r, r+n);

                //per(); //需要输出图像时再打开

                //遍历最后一行, 是否渗透 (注意这里的-1, 因为多了一个虚顶点)
                for(int i = n*n-n-1; i<n*n-1; i++){
                    if(quickUnion::find(sites,i) == quickUnion::find(sites,n*n))
                        percolate = true;
                }
                /*
                //调试,查看状态
                if(t==50){
                    showSites();
                    cout<<endl;     
                }
                if(t==100){
                    showSites();
                    cout<<endl;     
                }
                if(t==200){
                    showSites();
                    cout<<endl;     
                }*/
                
            }
            //showSites(); //完成一个输出最终渗透图
            return t/(n*n); 
        }    
};

class PercolationStats{
    private:
        double miu;
        double sigem;
        int t;
    public:
        PercolationStats(int N, int T){ // perform T independent computational experiments on an N-by-N grid
            t = T;
            double sum = 0.0;
            double cha = 0.0;
            vector<double> s;
            for(int i=0; i<T; i++){
                Percolation *P = new Percolation(N);
                double simu = P->simulation();
                sum += simu;
                s.push_back(simu);
                delete P;
            }
            miu = sum/T;
            for(auto i=s.begin();i<s.end();i++){
                cha += (*i-miu)*(*i-miu);  //计算sigem
            }
            sigem = sqrt(cha/(T-1));
            cout<<"values after creating PercolationStats("<<N<<","<<T<<')'<<endl;
        }

        double mean(){ // sample mean of percolation threshold
            return miu;
        }
        double stddev(){ // sample standard deviation of percolation threshold
            return sigem;
        }
        double confidenceLo(){ // returns lower bound of the 95% confidence interval
            return miu-(1.96*sigem/sqrt(double(t)));
        }
        double confidenceHi(){ // returns upper bound of the 95% confidence interval
            return miu+(1.96*sigem/sqrt(double(t)));
        }
        void showResult(){
            cout<<"mean()\t\t\t="<<setprecision(16)<<mean()<<endl;
            cout<<"stddev()\t\t="<<setprecision(16)<<stddev()<<endl;
            cout<<"confidenceLow()\t\t="<<setprecision(16)<<confidenceLo()<<endl;
            cout<<"confidenceHigh()\t="<<setprecision(16)<<confidenceHi()<<endl;
        }
        //static void main(String[] args) // test client, described below
};

int main(){
    srand(time(0));
    clock_t start, end;
    start = clock();
    
    PercolationStats P(180, 10);
    P.showResult();

    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ） 
    return 0;
}//不用vector确实快一些