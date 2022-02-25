// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include<bits/stdc++.h>
using namespace std;

//思路, 一个指针需要走两遍时, 不妨用两个指针前后走


struct ListNode{
    int m_nkey;
    ListNode* m_pNext;
};

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

//===================实现===============
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
    if(pListHead == nullptr || k<1)
        return nullptr;

    ListNode *pAhead = pListHead, *pBehind = pListHead;
    while(k > 1){
        if(pAhead->m_pNext != nullptr)
            pAhead = pAhead->m_pNext;
        else   
            return nullptr;
        k--;
    }
    while(pAhead->m_pNext != nullptr){
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}
// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试空链表
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(nullptr, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}