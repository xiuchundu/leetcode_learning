/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int min(int a, int b){
    return a < b ? a : b;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int i = 0, j, index=0;

    if (matrix == NULL || matrixSize == 0 || (matrixColSize == NULL) || (*matrixColSize == 0) || (returnSize == NULL)) {
        *returnSize = 0;
        return NULL;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    int loop = (min(m, n) + 1) / 2;
    int *res = malloc(sizeof(int) * m * n);

    while(i<loop){
        for (j = i; j < n-i; j++) {
            res[index++] = matrix[i][j];
        }

        for (j = i+1; j < m-i; j++) {
            res[index++] = matrix[j][(n-1)-i];
        }

        for (j = (n-1)-(i+1); j >= i && (m-1-i != i); j--) {
            res[index++] = matrix[(m-1)-i][j];
        }

        for (j = (m-1)-(i+1); j >= i+1 && (n-1-i) != i; j--) {
            res[index++] = matrix[j][i];
        }

        i++;
    }

    *returnSize = m * n;
    return res;
}