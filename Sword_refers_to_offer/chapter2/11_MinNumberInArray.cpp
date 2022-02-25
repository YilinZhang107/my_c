#include<bits/stdc++.h>
using namespace std;

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

//需要用到的求最小方法
int MinInOrder(int* numbers, int head, int end){
    int minest = numbers[head];
    for(int i=head; i<=end; i++){
        if(numbers[i]<minest)
            minest = numbers[i];
    }
    return minest;
}


int Min(int* numbers, int length){
    if(numbers==nullptr){
        cerr<<"InValid parameters!"<<endl;
        return 0;
    }

    int head=0, end=length-1;//作为两个指针
    int mid;
    //如果数列自身有序
    if(numbers[head]<numbers[end])
        return numbers[head];
    
    while(numbers[head] >= numbers[end]){
        //当head和end相邻时, end为起点即最小数字
        if(end-head == 1){
            break;
        }

        mid = (head+end)/2;
        //如果三个数字都相等,需要按顺序查找  (可能当范围比较小时连续的相同数字)
        if(numbers[head] == numbers[end] && numbers[head]==numbers[mid])
            return MinInOrder(numbers, head, end);

        //类二分查找缩小范围
        if(numbers[head] < numbers[mid])
            head = mid;
        else if(numbers[end] > numbers[mid])
            end = mid;
    }  
    return numbers[end];
}

// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(nullptr, 0, 0);

    return 0;
}