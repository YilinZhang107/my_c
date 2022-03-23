#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        //状态不再改变时,退出循环
        bool changed = true;
        int sum = 0;
        while(changed){
            int length = directions.length();
            changed = false;
            for(int i=0; i<length; i++){
                if(directions[i] == 'S')
                    continue;
                else if(directions[i] == 'L'){
                    if(i>=1){
                        if( directions[i-1]=='S'){
                        sum+= 1;
                        directions[i] = 'S';
                        changed = true;
                        }
                        else if(directions[i-1]=='R'){
                            sum+=2;
                            directions[i] = 'S';
                            directions[i-1] = 'S';
                            changed = true;
                            while(i+1<length && directions[i+1] == 'L'){
                                directions[i+1] = 'S';
                                sum++;
                                i++;
                            }
                        } 
                    }
                    else{
                        directions[i] = 'S';
                        while(directions[i+1] == 'L'){
                            i++;
                            directions[i] = 'S';
                        }
                    }
                }
                else if(directions[i] == 'R'){
                    if(i<length-1) {
                        if(directions[i+1]=='S'){
                            sum+= 1;
                            directions[i] = 'S';
                            changed = true;
                        }
                        else if(directions[i+1]=='L'){
                            sum+=2;
                            directions[i] = 'S';
                            directions[i+1] = 'S';
                            changed = true;
                            while(i+2<length && directions[i+2] == 'L'){
                                directions[i+2] = 'S';
                                sum++;
                                i++;
                            }
                        } 
                    }
                }
            }
            //不如不加
            for(auto i=directions.begin(); i!= directions.end(); i++){
            
                if(*i == 'S'){
                    while(*(i+1) == 'S')
                        directions.erase(i+1);
                }
            }
        }
        return sum;
    }
};

int main(){
    vector<int> nums = {6,6,6};
    string str = "LLLLRS";
    Solution s;
    cout<<s.countCollisions(str);
    return 0;
}