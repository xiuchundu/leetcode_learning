/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static char g_map[10][4] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

int g_num[10] = {0,0,3,3,3,3,3,4,3,4}; 

void DFS(char *dig, char **res, int *ans, int depth, int N, int *returnSize){
    if(depth == N){
        res[*returnSize] = malloc(sizeof(char) * (depth+1));
        for(int i=0; i<N; i++){
            res[*returnSize][i] = g_map[dig[i] - '0'][ans[i]];
        }
        
        res[*returnSize][N] = '\0';
        (*returnSize)++;
        return;
    }
    
    for(ans[depth] = 0; ans[depth] < g_num[dig[depth] - '0']; ans[depth]++){
        DFS(dig, res, ans, depth+1, N, returnSize);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    int len = strlen(digits);
    int ans[100] = {0}; //临时解空间
    int sum = pow(4, len); //最大的可能的个数
    *returnSize = 0; //必须初始化，不然会超出边界

    if(len == 0){
        *returnSize = 0;
        return NULL;
    }
    
    char **res = malloc(sizeof(char*) * sum); //申请解空间
    DFS(digits, res, ans, 0, len, returnSize);
    
    return res;
}