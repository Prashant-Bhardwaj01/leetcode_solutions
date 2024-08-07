/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int i=0;
    int *a = (int*)calloc(numsSize,sizeof(int));
    for(int i=0;i<numsSize;i++){
        a[i] = nums[nums[i]];
    }
    return a;
}
