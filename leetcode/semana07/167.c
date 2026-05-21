#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *resul = malloc(*returnSize * sizeof(int));
    int *p1 = numbers;
    int *p2 = numbers + (numbersSize - 1);
    int soma = 0;

    while ( p1 < p2) {
        if ( *p1 + *p2 == target ) {
            resul[0] = (p1 - numbers) + 1;
            resul[1] = (p2 - numbers) + 1;
            return resul;
        } else if ( *p1 + *p2 < target ) {
            p1++;
        } else {
            p2--;
        }
    }

    *returnSize = 0;
    free(numbers);
    return NULL;
}