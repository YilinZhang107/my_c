#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ToString(long long  &val, int &discount){
        char* chCode;
        chCode = new char[20];
        double t = val*1.0*(100-discount)/100.0;
        sprintf(chCode, "%.2lf", t);
        string str(chCode);
        delete[] chCode;
        return str;
    }


    string discountPrices(string sentence, int discount) {
        string ans = "";
        for(int i=0; i<sentence.size(); i++){
            if((i==0 && sentence[i]=='$') || 
                (i!=0 && sentence[i]=='$' && sentence[i-1]==' ')){
                // int end = sentence.find(' ', i);
                int end = 1;
                bool is = true;
                while(sentence[i+end] != ' ' && i+end < sentence.size()){
                    end++;
                }
                end--;
                for(int j=1; j<=end; j++){
                    if(sentence[i+j] > '9' || sentence[i+j]<'0'){
                        is = false;
                        break;
                    }
                }
                if(is && end != 0){
                    long long t = stoll(sentence.substr(i+1, end));
                    ans += '$'+ToString(t,discount);
                    i += end;
                }else{
                    ans += '$'+ sentence.substr(i+1, end);
                    i+=end;
                }
            }
            else{
                ans += sentence[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string sen ="k5 $7651913186 pw2o $6";
    cout<<s.discountPrices(sen,28);
    return 0;
}