int **g_return = NULL;
int depth = 0;
#define N_MAX 18
#define TRUE 1
#define FALSE 0
int *array = NULL;

int CalcTotal(int numsSize)
{
    int i;
    int total = 1;
    
    for (i = 1; i <= numsSize; i++) {
        total *= i;    
    }
    
    return total;
}

void dfs(int level, int N, int *tmp){
    if(level == N){
        array[N] = '\0';
        int *tmp = (int *)calloc(N, sizeof(int));
        if (tmp == NULL) {
            return;
        }

        memcpy(tmp, array, N*sizeof(int));
        g_return[depth] = tmp;
        depth += 1;
        return;  //返回，便于回退
    }
    for (int j = 1; j <= N; ++j) {
        int repeat = FALSE;
        for (int i = 0; i < level; ++i) {
            if(tmp[j-1] == array[i]){
                repeat = TRUE;
                break;
            }
        }
        if(repeat == FALSE){
            array[level] = tmp[j-1];
            dfs(level+1, N, tmp);
        }
    }
    return;
}

int ** permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int i;
    int g_totalNum = 0;
    int g_ways;
    if (numsSize <= 0) {
        g_ways = 0;
        *returnSize = g_ways;
        return;
    }

    g_totalNum = CalcTotal(numsSize);
    g_ways = 0;
    g_return = (int **)malloc(sizeof(int *) * g_totalNum);    
    if (g_return == NULL) {
        return NULL;
    }
          
    *returnColumnSizes = (int *)malloc(sizeof(int) * g_totalNum);

    for (i = 0; i < g_totalNum; i++) {       
        (*returnColumnSizes)[i] = numsSize;
    }
    
    array = malloc(sizeof(int)* N_MAX);
    if(numsSize == 1){
        *g_return = nums;
    }else{
        depth = 0;
        dfs(0, numsSize, nums); 
    
    }
    
    *returnSize = g_totalNum;
    return g_return;
}