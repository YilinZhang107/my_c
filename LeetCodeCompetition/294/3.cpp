#include<bits/stdc++.h>
using namespace std;

bool mycmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

bool same(double a,double b){
    return fabs(b-a) < 0.000000000005; 
}

class Solution {
public:
   

    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), mycmp);
        // for(vector<int> i: stockPrices)
        //     cout<<i[0]<<" "<<i[1]<<endl;
        double k, b,k1,b1;
        int cnt=0;
        if(stockPrices.size() == 1)
            return 0;
        if(stockPrices.size() == 2)
            return 1;
        cnt++;
        k = (stockPrices[1][1]-stockPrices[0][1])*1.0 / (stockPrices[1][0]-stockPrices[0][0])*1.0;
        // cout<<k;
        b = stockPrices[0][1] - k*stockPrices[0][0];
        // cout<<b;
        for(int i=2; i<stockPrices.size(); i++){
            k1 = (stockPrices[i][1]-stockPrices[i-1][1])*1.0 / (stockPrices[i][0]-stockPrices[i-1][0])*1.0;
            b1 = stockPrices[i][1] - k1*stockPrices[i][0];
            if(!(same(k,k1) && same(b,b1))){
                cnt++;
                k = k1;
                b = b1;
            } 
        }
        return cnt;
    }
};

int main(){
    Solution s;
    //vector<vector<int>> stock = {{1,7},{2,6},{3,5},{4,4},{5,4},{6,3},{7,2},{8,1}};
    vector<vector<int>> stock = {{1,1000000000},{1000000000,1000000000},{999999999,1},{2,999999999}};
    cout<<s.minimumLines(stock);
}