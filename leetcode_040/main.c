/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_RET  1000

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

void dfs(int *candidates, int candidatesSize, int target, int *returnSize, int *columnSizes, int ** ret, int *eachItem, int eachItemIndex, int level)
{
    if (target == 0 && eachItemIndex != 0) {
        ret[*returnSize] = (int *)calloc(eachItemIndex, sizeof(int));
        memcpy(ret[*returnSize], eachItem, eachItemIndex * sizeof(int));
        columnSizes[*returnSize] = eachItemIndex;
        (*returnSize)++;
        return;
    }
    for (int i = level; i < candidatesSize; i++) {
        if (target < 0 ) {
            return;
        }
        if((i>level && candidates[i] == candidates[i-1])){
            continue;
        }
        eachItem[eachItemIndex] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, columnSizes, ret, eachItem, eachItemIndex + 1, i+1);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (candidates == NULL || candidatesSize <= 0) {
        return NULL;
    }
    int **ret = (int **)calloc(MAX_RET, sizeof(int *));
    int *columnSizes = (int *)calloc(MAX_RET, sizeof(int));
    int *eachItem = (int *)calloc(MAX_RET, sizeof(int));
    int eachItemIndex = 0;

    qsort(candidates, candidatesSize, sizeof(int), compare);
    dfs(candidates, candidatesSize, target, returnSize, columnSizes, ret, eachItem, eachItemIndex, 0);
    *returnColumnSizes = columnSizes;
    return ret;
}