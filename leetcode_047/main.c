/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cnt = 0;
static int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

static void dfs(int *nums, int size, int *stack, int len,
                bool *used, int **results, int *count)
{
    int i;
    if (len == size) {
        cnt += 1;
        results[*count] = malloc(len * sizeof(int));
        memcpy(results[*count], stack, len * sizeof(int));
        (*count)++;
    } else {
        for (i = 0; i < size; i++) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                used[i] = true;
                stack[len] = nums[i];
                dfs(nums, size, stack, len + 1, used, results, count);
                used[i] = false;
            }
        }
    }
}

/**
 ** Return an array of arrays of size *returnSize.
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
static int **permuteUnique(int* nums, int numsSize, int* returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0, cap = 1000;
    int *stack = malloc(numsSize * sizeof(int));
    int **results = malloc(cap * sizeof(int *));
    bool *used = malloc(numsSize);
    memset(used, false, numsSize);
    *returnSize = 0;
    dfs(nums, numsSize, stack, 0, used, results, returnSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return results;
}