void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, tmp;
    for(i=0; i<matrixSize; i++){
        for(j=0; j<i; j++){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for(i=0; i<matrixSize; i++){
        for(j=0; j<(matrixSize/2); j++){
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = tmp;
        }
    }
}