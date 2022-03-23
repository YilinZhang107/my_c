#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *head = nullptr;
        for(int i=0; i<descriptions.size(); i++){
            //不存在这个child节点
            TreeNode *c = find(descriptions[i][1], head);
            TreeNode *f = find(descriptions[i][0], head);
            if(c == nullptr){
                c = new TreeNode(descriptions[i][1]);
                //c = child;
            }
            if(f == nullptr){
                f = new TreeNode(descriptions[i][0]);
                if(find(descriptions[i][0], head->left) == nullptr &&
                    find(descriptions[i][0], head->right) == nullptr)
                    head = f;
            }
            if(descriptions[i][2] == 1)
                f->left = c;
            else
                f->right = c;
        }
        return head;
    }

    TreeNode* find(int value, TreeNode *head){
        if(head == nullptr)
            return nullptr;
        if(head->val == value)
            return head;
        if(find(value,head->left) != nullptr)
            return find(value, head->left);
        if(find(value,head->right) != nullptr)
            return find(value, head->right);
        return nullptr;
    }
};

int main(){
    Solution s;

    vector<vector<int>> nums ={{85,82,1},{74,85,1},{39,70,0},{82,38,1},{74,39,0},{39,13,1}};
    TreeNode *head = s.createBinaryTree(nums);
    return 0; 
}