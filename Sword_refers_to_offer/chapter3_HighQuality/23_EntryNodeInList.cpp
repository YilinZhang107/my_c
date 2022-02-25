// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。


#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int m_nkey;
    ListNode* m_pNext;
};

ListNode* EntryNodeOfLoop(ListNode* pHead){
    if(pHead ==nullptr)
        return nullptr;

    ListNode *pQuick = pHead, *pSlow = pHead;
    int numInCircle = 0;
    //先快走2,慢走1, 相遇表示有环,再走一圈到相同的求环中个数
    while(pQuick->m_pNext != nullptr){
        pQuick = pQuick->m_pNext;
        if(pQuick->m_pNext != nullptr)
            pQuick = pQuick->m_pNext;
        else
            break;
        pSlow = pSlow->m_pNext;
        //找到
        if(pSlow == pQuick){
            pQuick = pQuick->m_pNext;
            numInCircle++;
            while(pSlow != pQuick){
                pQuick = pQuick->m_pNext;
                numInCircle++;
            }
            break;
        }
    }
    if(numInCircle == 0)//不存在环
        return nullptr;
    
    //先让quick走num步,然后一起走,重合时便是入口
    pQuick = pHead;
    pSlow = pHead;
    while(numInCircle != 0){
        numInCircle--;
        pQuick = pQuick->m_pNext;
    }
    while(pQuick != pSlow){
        pQuick = pQuick->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    return pQuick;
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

// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}