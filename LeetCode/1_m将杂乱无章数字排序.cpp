#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<string> numsTrueValue(n, "");
        for(int i=0; i<n; i++)
            numsTrueValue[i] = to_string(nums[i]);
        for(int i=0; i<n; i++){
            for(int j=0; j<numsTrueValue[i].size(); j++){
                numsTrueValue[i][j] = mapping[numsTrueValue[i][j]-'0'] +'0';
            }
        }
        vector<int> numsTV;
        for(string s:numsTrueValue)
            numsTV.push_back(stol(s));

        MergeSort(numsTV,nums,0,n-1);
        return nums;
    }

    
    void Merge(vector<int> &arr,vector<int> &b,int low,int mid,int high){
        //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
        int i=low,j=mid+1,k=0; //mid+1为第2有序区第1个元素，j指向第1个元素
        int *temp=new(nothrow) int[high-low+1]; //temp数组暂存合并的有序序列
        int *tempb=new(nothrow) int[high-low+1];
        if(!temp){ //内存分配失败
            cout<<"error";
            return;
        }
        while(i<=mid&&j<=high){
            if(arr[i]<=arr[j]){ //较小的先存入temp中
                temp[k++]=arr[i++];
                tempb[k-1]=b[i-1];
            }
            else{
                temp[k++]=arr[j++];
                tempb[k-1]=b[j-1];
            }
        }
        while(i<=mid){//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
            temp[k++]=arr[i++];
            tempb[k-1]=b[i-1];
        }
        while(j<=high){//同上
            temp[k++]=arr[j++];
             tempb[k-1]=b[j-1];
        }
        for(i=low,k=0;i<=high;i++,k++){//将排好序的存回arr中low到high这区间
            arr[i]=temp[k];
            b[i]=tempb[k];
        }
        delete []temp,tempb;//删除指针，由于指向的是数组，必须用delete []
    }
    
    //用递归应用二路归并函数实现排序——分治法
    void MergeSort(vector<int> &arr,vector<int> &b,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            MergeSort(arr,b,low,mid);
            MergeSort(arr,b,mid+1,high);
            Merge(arr,b,low,mid,high);
        }
    }

};

int main(){
    Solution s;
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    nums = s.sortJumbled(mapping, nums);

    return 0;
}