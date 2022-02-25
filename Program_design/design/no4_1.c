#include<stdio.h>

int get(int array[], int low, int high)
{
    int key = array[low];  //基准数据
    while(low<high)
    {
        while(low<high && array[high]>=key)//默认基准从左边开始，从右边开始比较
            high--;                      //队尾的元素大于等于基准数据时，就一直向前挪动high指针
    
        if(low < high)  //找到比array[low]小的数后，就把high值赋给它
            array[low] = array[high];

        while(low < high && array[low] <= key)//队首元素小于等于基准数据时，就一直向后挪动low指针
            low++;

        if(low < high)//找到比array[high]大的数时，就把前面的array[low]赋给它
            array[high] = array[low];
    }
    //跳出循环时low和high相等，此时的low和high就是key的正确索引位置
    //把基准数据赋给正确位置
    array[low] = key;
    return high;
}

void sort(int array[], int low, int high) //实现递归
{
    if(low < high)
    {
        int standard = get(array, low, high);
        //递归
        sort(array, low, standard-1);
        sort(array, standard+1, high);
    }
}

int main()
{
    int n[50], i;
    char c;
    printf("请输入您想要排序的数组:");
    for(i = 0; i < 50; i++)
    {
        scanf("%d%c",&n[i], &c);
        if(c==10)
            break;
    }
    sort(n, 0, i);
    printf("排序后的数列为：");
    for(int l = 0; l <= i; l++)
    {
        printf("%d ",n[l]);
    }
}