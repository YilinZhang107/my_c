#include<bits/stdc++.h>
//#include<6.h>
using namespace std;


// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

struct ListNode{
    int m_nkey;
    ListNode* m_pNext;
};

void PrintListReversingly_Iteratively(ListNode* pHead){
    if (pHead == nullptr)
        return ;
    
    stack<ListNode*> nodes;  //栈存储
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        cout<<pNode->m_nkey<<'\t';
        nodes.pop();
    }
}
//====================其他链表的实现部分============
//创建一个节点,返回指针
ListNode* CreateListNode(int key){  
    ListNode* pHead = new ListNode;
    if (pHead == nullptr){
        cout<<"创建错误,请重试!"<<endl;
        exit(0);
    }
    pHead->m_nkey = key;
    pHead->m_pNext = nullptr;
    return pHead;
}
//连接两个节点
void ConnectListNodes(ListNode* pNode1, ListNode* pNode2){
    if(pNode1==nullptr || pNode2 == nullptr){
        cout<<"传入节点错误!"<<endl;
        return;
    }
    pNode1->m_pNext = pNode2;
}
//打印一个节点
void PrintListNode(ListNode *pNode){
    if(pNode != nullptr)
        cout<<pNode->m_nkey<<endl;
    return;
}
//打印链表
void PrintList(ListNode* pHead){
    if(pHead==nullptr){
        cout<<"Null"<<endl;
        return;
    }
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        cout<<pNode->m_nkey<<'\t';
        pNode = pNode->m_pNext;
    }
    cout<<endl;
}
//销毁链表
void DestroyList(ListNode* pNode1){
    if(pNode1 == nullptr)
        return;
    while(pNode1->m_pNext != nullptr){
        ListNode* pNow = pNode1;
        pNode1 = pNode1->m_pNext;
        delete pNow;
    }
    delete pNode1;
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    //PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
