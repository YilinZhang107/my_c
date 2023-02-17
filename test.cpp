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
class Solution {
public:
    set<int> nodes;
    map<int, vector<TreeNode*>> fa;
    queue<int> q,qn;
    void makefa(TreeNode* root, TreeNode* father){
        if(root == NULL)
            return;
        fa[root->val] = {father,root};
        nodes.insert(root->val);
        makefa(root->left, root);
        makefa(root->right,root);
    }
    
    void infect(){
        while(!q.empty()){
            int n = q.front();
            q.pop();
            if(nodes.count(n)){
                TreeNode* t = fa[n][1];
                nodes.erase(n);
                if(t->left!= NULL){
                    nodes.erase(t->left->val);
                    qn.push(t->left->val);
                }
                if(t->right != NULL){
                    nodes.erase(t->right->val);
                    qn.push(t->right->val);
                }
                if(fa[n][0] != NULL){
                    nodes.erase(fa[n][0]->val);
                    qn.push(fa[n][0]->val);
                }
            }
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        makefa(root, NULL);
        int ans = 0;
        q.push(start);
        while(!nodes.empty()){
            infect();
            q = qn;
            qn = queue<int>();
            ans++;
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int start = stringToInteger(line);
        
        int ret = Solution().amountOfTime(root, start);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}