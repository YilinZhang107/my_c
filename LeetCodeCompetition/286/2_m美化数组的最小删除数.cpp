#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //直接用erase在数组中操作会超时,所以写的很臭, 但过了
    int minDeletion(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int head = 0, now = head+1;
        int ans = 0;
        int len = 0;
        int n = nums.size();
        while(now <= n-1){
            if(nums[head] == nums[now]){
                while(now <= n-1 && nums[head] == nums[now]){
                    now++;
                    ans++;
                }
                head = now+1;
                now = head+1;
                if(now <= n-1)
                    len+=2;
                else{
                    if(head == n-1)
                        len+=3;
                    else if(head == n+1)//所有数字一样时会这样
                        len+=1;
                    else 
                        len+=2;
                    break;
                }
            
            }
            else{
                head+=2;
                now = head+1;
                if(now <= n-1)
                    len+=2;
                else{
                    if(head == n-1)
                        len+=3;
                    else    
                        len+=2;
                    break;
                }
            }
        }
        if(len & 1){
            ans++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> can = {1,1};
    cout<<s.minDeletion(can);
    return 0;
}