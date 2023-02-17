#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while(n != 1){
            
            for(int i=0; i<n; i++){
                if(i%2){//奇
                    nums[i] = max(nums[2*i], nums[2*i+1]);
                }
                else{
                    nums[i] = min(nums[2*i], nums[2*i+1]);
                }
            }
            n/=2;
        }
        return nums[0];
    }
};

int main(){
    
    int n = nums.size();
        while(n != 1){
            
            for(int i=0; i<n; i++){
                if(i%2){//奇
                    nums[i] = max(nums[2*i], nums[2*i+1]);
                }
                else{
                    nums[i] = min(nums[2*i], nums[2*i+1]);
                }
            }
            n/=2;
        }
        return nums[0]; 
=======
#define vi vector<int>
#define MAX 99999999
#define INF 0x3f
#define endl '\n'
#define _for(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a; i<=b;i++)
#define bug(a)  cout<<#a<<": "<<a<<endl;
#define pb push_back
#define mp make_pair
int n,m,k;


int main(){
    
    string  s= "1 and is the 2";
    // s.erase(5,1);
    // bug(s);
    // s.replace(5,1,"XXX");
    // bug(s);
    vi v = {1,2,3,1,2,4,1,23,87,12,3,23};
    sort(v.begin(),v.end());
    rep(i,0,v.size()-1) cout<<v[i]<<" ";
    cout<<endl;
    v.insert(v.begin()+2, 10);
    rep(i,0,v.size()-1) cout<<v[i]<<" ";

>>>>>>> c1e6de8d5ab6f0c1b49e5ac1156e2109fdf19715
    return 0;
}