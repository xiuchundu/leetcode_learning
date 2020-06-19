#define MAX_RET  1000

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
        if (target < 0) {
            return;
        }
        eachItem[eachItemIndex] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, columnSizes, ret, eachItem, eachItemIndex + 1, i);
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (candidates == NULL || candidatesSize <= 0) {
        return NULL;
    }
    int **ret = (int **)calloc(MAX_RET, sizeof(int *));
    int *columnSizes = (int *)calloc(MAX_RET, sizeof(int));
    int *eachItem = (int *)calloc(MAX_RET, sizeof(int));
    int eachItemIndex = 0;
    dfs(candidates, candidatesSize, target, returnSize, columnSizes, ret, eachItem, eachItemIndex, 0);
    *returnColumnSizes = columnSizes;
    return ret;
}