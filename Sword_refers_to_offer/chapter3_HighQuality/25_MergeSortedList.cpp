
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int m_nkey;
    ListNode* m_pNext;
};

//main 
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;
    ListNode *newHead;
    if(pHead1->m_nkey < pHead2->m_nkey){
        newHead = pHead1;
        newHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else{
        newHead = pHead2;
        newHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
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
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
