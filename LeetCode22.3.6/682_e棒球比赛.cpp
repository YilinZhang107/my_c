#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> numbers;
        int sum=0, index=0;
        for(string s:ops){
            if(s == "C"){
                index--;
                numbers.erase(numbers.begin()+index);
            }
            else if(s == "D"){
                numbers.push_back(numbers[index-1]*2);
                index++;
            }
            else if(s == "+"){
                numbers.push_back(numbers[index-1] + numbers[index-2]);
                index++;
            }
            else{
                numbers.push_back((int)stol(s));
                index++;
            }
        }
        for(auto i=numbers.begin(); i!=numbers.end();i++){
            sum+=*i;
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<string> str = {"5","2","C","D","+"};
    cout<<s.calPoints(str);
    return 0;
}