#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//链表操作题, 先把零之间的数字相加, 再跳着除去0节点,复杂度2n
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* now = head->next;
        while(now != nullptr){
            if(now->val != 0){
                int sum = now->val;
                ListNode *notZero = now->next;
                while(notZero->val != 0){
                    sum += notZero->val;
                    notZero = notZero->next;
                }
                now->val = sum;
                now->next = notZero;//此时连接到下一个0节点
            }
            now = now->next;
        }
        head = head->next;
        now = head;
        while(now != nullptr){
            now->next = now->next->next;
            now = now->next;
        }
        return head;
    }
};