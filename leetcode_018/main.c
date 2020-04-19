/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) {
        return 0;
    }
    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 3);
    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;
    short begin = 0;
    short end = numsSize - 1;
    int loopTarget = 0;
    int subTarget = 0;
    
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 3);
    qsort(nums, numsSize, sizeof(int), comp);
    ret[*returnSize] = malloc(sizeof(int) * 4);
    
    while (begin + 2 < end) {
        left = begin + 1;
        right = end;
        loopTarget = target - nums[begin];
        while (left + 1 < right) {
            int i = left + 1;
            int j = right;
            subTarget = loopTarget - nums[left];
            while (i < j) {
                if (nums[i] + nums[j] < subTarget) {
                    i++;
                } else if (nums[i] + nums[j] > subTarget) {
                    j--;
                } else {
                    ret[*returnSize][0] = nums[begin];
                    ret[*returnSize][1] = nums[left];
                    ret[*returnSize][2] = nums[i];
                    ret[*returnSize][3] = nums[j];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    ret[*returnSize] = malloc(sizeof(int) * 4);

                    while(nums[i] == nums[++i] && i < j) {}
                    while(nums[j] == nums[--j] && i < j) {}
                }
            }
            while(nums[left] == nums[++left] && left + 1 < right) {}
        }
        while(nums[begin] == nums[++begin] && begin + 2 < end) {}
    }
    
    return ret;
}