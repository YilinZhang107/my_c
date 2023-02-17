#include<bits/stdc++.h>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0,t =0;
        ListNode *ans = nullptr, *p,*tp;
        while(l1!=nullptr || l2!= nullptr){
            
            if(l1!=nullptr){
                t += l1->val;
                tp = l1;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                t+=l2->val;
                tp = l2;
                l2 = l2->next;
            }
            tp->val = (t+c)%10;
            c = (t+c)/10;
            if(ans == nullptr){
                ans = tp;
                p = ans->next;
            }
            else{
                p = tp;
                p = p->next;
            }
            t = 0;
        }
        return ans;
    }
};

int main(){
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    l1->next = new ListNode(3);
    l1 = s.addTwoNumbers(l1,l2);
    cout<<l1->val;
    return 0;
}