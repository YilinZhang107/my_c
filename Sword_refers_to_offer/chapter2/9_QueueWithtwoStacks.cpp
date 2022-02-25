#include<bits/stdc++.h>
using namespace std;

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。


template <typename T>
class CQueue{
public:
    CQueue(){}
    ~CQueue(){}
    
    // 在队列末尾添加一个结点
    void appendTail(const T& node){
        stack1.push(node);
    }

    // 删除队列的头结点
    T deleteHead(){
        T head;
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty())
            cerr<< "Error: queue is empty!";
            //return head;
        head = stack2.top();
        stack2.pop();
        return head;
    }

private:
    stack<T> stack1;
    stack<T> stack2;
};

// ====================测试代码====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');

    head = queue.deleteHead();
    return 0;
}