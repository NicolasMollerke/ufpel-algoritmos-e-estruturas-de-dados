#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder ( int** mat, int matSize, int* matColSize, int* returnSize );

int main ( int argc, char const *argv[] ) {
    int **mat, matSize, *matColSize, *returnSize, *resul;

    resul = findDiagonalOrder ( mat, matSize, matColSize, returnSize );

    free(resul);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder ( int** mat, int matSize, int* matColSize, int* returnSize ) {
    int *resul;
    int p = 0, l = 0, c = 0;

    *returnSize = matSize * ( *matColSize );

    resul = malloc(*returnSize * sizeof(int));

    //coluna + linha = pare sobe
    //coluna + linha = impar desce
     
    while ( p < *returnSize ){
        if ( (c + l) % 2 == 0 ){ //pares
            if ( (c + 1) == *matColSize ) { //ultima coluna
                resul[p] = mat[l][c];
                l++;
                p++;
            } else if ( (l - 1) < 0 ) { //primeira linha
                resul[p] = mat[l][c];
                c++;
                p++;
            } else {
                resul[p] = mat[l][c];
                c++;
                l--;
                p++;
            }
        } else if ( (c + l) % 2 != 0 ) {
            if ( (l + 1) == matSize ) { //ultima linha
                resul[p] = mat[l][c];
                c++;
                p++;
            } else if ( (c - 1) < 0 ) { //primeira coluna
                resul[p] = mat[l][c];
                l++;
                p++;
            } else {
                resul[p] = mat[l][c];
                c--;
                l++;
                p++;
            }
        }
    }

    return resul;
}
