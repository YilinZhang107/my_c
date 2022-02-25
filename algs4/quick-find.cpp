#include<bits/stdc++.h>
#include<time.h>
using namespace std;

class site{
    private:
        int number;  //序号,在矩阵中的位置:n=i*n+j
        bool isblocked;  //是不是黑
        bool isfull;  //是不是被填充
        
    public:
        int id;    //索引
        int sz=1;    //(由触电索引的)各个根节点所对应的分量的大小
        site(int n,bool iB=true,bool iF=false):number(n),id(n),isblocked(iB),isfull(iF) {}
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

//quick-find算法
class quickFind{
    public:
        static int find(vector<site> &s, int p){ //p = i*n+j
            return s[p].id;
        }
        //归并到同一个分量中
        static void myunion(vector<site> &s, int p, int q){
            int pID = find(s,p);
            int qID = find(s,q);
            if(pID==qID) return;//如果已经在同一个分量中不改变
            for(int i = 0; i<s.size(); i++){//把分量重命名为小的一方
                if(pID>qID){
                    if(s[i].id==pID)
                        s[i].id = qID;
                }
                else{
                    if(s[i].id==qID)
                        s[i].id = pID;
                }
            }
        }
};

class Percolation {
    private:
        vector<site> sites;  //site类容器
        int n;  //大小
        bool percolate = false;
        double t = 0;  //渗透时所进行的操作次数

    public:
        Percolation(int N){ // create N-by-N grid, with all sites blocked
            n = N;
            for(int i=0; i < n; i++){
                for(int j=0; j< n; j++){
                    sites.push_back(i*n+j);
                }
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
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
            for(int i=0; i<sites.size();i++){
                if(sites[i].id<n && sites[i].isOpen()) 
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
                    t++;//计数
                }

                //以上左右下的顺序,与周围的site进行union, id定为最小的
                if(r>=n && sites[r-n].isOpen()) //与上方union,排除第一行
                    quickFind::myunion(sites, r, r-n);
                if(r%n!=0 && sites[r-1].isOpen()) //与左union, 排除第一列
                    quickFind::myunion(sites, r, r-1);
                if((r+1)%n!=0 && sites[r+1].isOpen()) //与右union, 排除第n列
                    quickFind::myunion(sites, r, r+1);
                if((r+n)<n*n && sites[r+n].isOpen()) //与下union, 排除第n行
                    quickFind::myunion(sites, r, r+n);

                per(); //需要输出图像时再打开

                //遍历最后一行, 是否渗透  在union时始终以最小id的为准,所以id小于n时渗透
                for(int i = sites.size()-n; i<sites.size(); i++){
                    if(sites[i].id<n)
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
            showSites(); //完成一个输出最终渗透图
            //cout<<endl;
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
    
    cout<<"quick-find:"<<endl;
    PercolationStats P(20, 10);
    P.showResult();

    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ） 
    return 0;
}