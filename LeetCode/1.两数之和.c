int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *n = malloc(sizeof(int)*2);
    for(int i=0; i<numsSize; i++){
        int jian = target-nums[i];
        for(int j=i+1; j<numsSize; j++){
            if(nums[j]==jian){
                n[0] = i;
                n[1] = j;
                return n;
            }
        }
    }
    return 0;
}