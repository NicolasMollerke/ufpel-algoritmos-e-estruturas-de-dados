int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *resul;
    int p = 0;

    *returnSize = matSize * (*matColSize);

    resul = malloc(*returnSize * sizeof(int));


    for (int l=0; l <= matSize; l++){
        for (int c=0; c <= *matColSize; c++){
            while(p < *returnSize){
                resul[p] = mat[l][c];
                p++; 
            }
        }
    }

    return resul;
    
}
