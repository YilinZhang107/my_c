//奇偶分开排序, 偶前奇后, 有头节点

#include<bits/stdc++.h>
using namespace std;

//链表节点定义
struct ListNode{
    int value;
    ListNode *next;
};

//创建一个节点
ListNode* createNode(int value){
    ListNode *newNode = new ListNode();
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

//在链表中插入新元素,只写这一个函数
void insert(ListNode *L, int v){
    ListNode *last=L;
    L = L->next;
    ListNode *now = createNode(v);
    if(v & 1){ //奇数
        while(L!=NULL  && ((L->value&1)==0 ||( L->value&1 && L->value > v ))){
            last = L;
            L = L->next;
        }
    }
    else{//偶数
        while(L!=NULL  && (L->value&1)==0 && L->value < v ){
            last = L;
            L = L->next;
        }
        
    }
    last->next = now;
    now->next = L;
}

//打印链表
void printList(ListNode *head){
    head = head->next;//处理头节点
    while (head != NULL){
        cout<<head->value;
        if(head->next != NULL){
            cout<<"->";
            head = head->next;
        }
        else
            break;
    }
}

int main(){
    ListNode *head = createNode(0);
    int num;
    while (cin>>num) { //输入0结束
        if(num != 0)
            insert(head, num);
        else
            break;
    }
    printList(head);
    return 0;
}