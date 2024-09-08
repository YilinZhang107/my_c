#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value=0;
    int weight;
    string code = "";
    Node *left, *right;
};

bool cmp(Node *a, Node *b){
    if(a->weight != b->weight)
        return a->weight > b->weight;
    return a->value < b->value;
}
// struct CompareNode {
//     bool operator ()(const Node *a, const Node *b) const {
//         return a->weight < b->weight;
//     }
// };

void generateCode(Node *root, string code){
    if(root->value == 0){//非叶子节点
        generateCode(root->left, code+"0");
        generateCode(root->right, code+"1");
    }
    else{
        cout<<"Node value:"<<root->value<<" Code:"<<code<<endl;
    }
}

int main(){
    int n, i;
    // multiset<Node*, CompareNode> s;
    vector<Node*> v;
    cout<<"total num:";
    cin>>n;
    for(i=0; i<n; i++){
        cout<<"the "<<i<<"-th Node value and weight:";
        Node *t = new Node();
        cin>>t->value>>t->weight;
        // s.insert(t);
        v.push_back(t);
    }    
    
    for(i=n; i>1; i--){
        //排序找到最小权值点, 为了之后删除元素时间复杂度为O(1), 排序时从大到小排
        sort(v.begin(), v.end(), cmp); 
        //创建新节点
        Node *parent = new Node();
        parent->weight = v[i-1]->weight + v[i-2]->weight;
        parent->left = v[i-1];
        parent->right = v[i-2];
        v.pop_back();
        v.pop_back();
        v.push_back(parent);
    }
    //最终v[0]为根节点,进行编码
    generateCode(v[0], "");

    return 0;
}

