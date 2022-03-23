#include<bits/stdc++.h>
using namespace std;

    
    // Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };
    

class Solution {
public:
    //看到的一个哈希表
    vector<int> postorder_1(Node* root) {
        stack<Node*> s;
        unordered_map<Node*, int> cnt;//记录已遍历的子节点个数

        vector<int> ret;
        if (root) {
            s.push(root);
        }
        while (!s.empty()) {
            root = s.top();
            if (cnt.find(root) == cnt.end()) {
                cnt[root] = 0;
            }
            //root的子节点全部遍历完时，遍历自己
            else if(cnt[root] == root->children.size()){
                ret.push_back(root->val);
                s.pop();
            }
            else {
                s.push(root->children[cnt[root]]);
                ++cnt[root];
            }
        }
        return ret;
    }

    vector<int> postorder(Node* root) {
        vector<int> backNums;
        back(root, backNums);
        return backNums;
    }

    void back(Node* root, vector<int> &backNums){
        if(root == nullptr)
            return;
        for(Node* r : root->children){
            back(r, backNums);
        }
        backNums.push_back(root->val);
    }
};