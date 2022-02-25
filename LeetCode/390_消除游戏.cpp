/*
列表 arr 由在范围 [1, n] 中的所有整数组成，并按严格递增排序。请你对 arr 应用下述算法：

从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。
重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。
不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
给你整数 n ，返回 arr 最后剩下的数字。
*/

#include <bits/stdc++.h>
using namespace std;

//思路,n<10^9 , 没办法储存,然后删除数字, 只需要记录起点和终点,
//以及循环的次数

int lastRemaining(int n) {
    int min=1, max=n;
    int distance = 1;
    while(n != 1){ // 剩余的数字数量
        //从前往后
        if(n & 1 == 1)//是奇数
            max -= distance;
        min += distance;
        
        n /= 2;  
        distance *= 2;

        //从后往前
        if(n != 1){
            if(n & 1 == 1)//是奇数
                min += distance;
            max -= distance;
              
            n/= 2;
            distance *= 2;
        }
    }
    return min;
}

//============test===========
int main(){
    int n = lastRemaining(10000000);
    cout<<n;
    return 0;
}