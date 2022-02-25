// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int m_nkey;
    ListNode* m_pNext;
};

//main
ListNode* ReverseList_1(ListNode* pHead){
    if(pHead == nullptr)
        return nullptr;
    ListNode *pNow = pHead;
    ListNode *pBehind = pHead, *pAhead = pHead->m_pNext;
    pBehind->m_pNext = nullptr;
    while(pAhead != nullptr){
        pNow = pAhead;
        pAhead = pNow->m_pNext;
        pNow->m_pNext = pBehind;
        pBehind = pNow;
    }
    return pNow;
}
//递归实现, 妙绝
ListNode* ReverseList(ListNode* pHead){
    if(pHead == nullptr || pHead->m_pNext == nullptr)
        return pHead;
    ListNode *newHead = ReverseList(pHead->m_pNext);
    pHead->m_pNext->m_pNext = pHead;
    pHead->m_pNext = nullptr;
    return newHead;
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
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}