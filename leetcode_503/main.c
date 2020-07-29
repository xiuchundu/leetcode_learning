/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 10000
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *stack = calloc(MAX_NUM, sizeof(int)); /* 模拟栈 */
    int *result = calloc(numsSize, sizeof(int));
    int top = -1;/* 模拟栈顶 */
    memset(result, -1, sizeof(int) * numsSize);
    for (int i = 0; i < 2 * numsSize -1; i++) {
        int idex = i % numsSize;/* 取模，才能防止下标溢出 */
        while (top > -1 && nums[stack[top]] < nums[idex]) { /* 出栈 */
            result[stack[top--]] = nums[idex];
        }
        stack[++top] = idex;/* 入栈 */
    }
    *returnSize = numsSize;
    free(stack);
    return result;
}