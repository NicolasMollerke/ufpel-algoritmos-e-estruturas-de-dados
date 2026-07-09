void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int* arr, int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int* arr, int baixo, int alto) {
    if (baixo < alto) {
        int pivo_idx = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pivo_idx - 1);
        quickSort(arr, pivo_idx + 1, alto);
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int menor;
    if ( nums1Size > nums2Size ) {
        menor = nums2Size;
    } else {
        menor = nums1Size;
    }

    int *resul = malloc(menor * sizeof(int));

    quickSort(nums1, 0, nums1Size - 1);
    quickSort(nums2, 0, nums2Size - 1);

    int i = 0;
    int j = 0;
    int p = 0;

    while ( i < nums1Size && j < nums2Size ) {
        if ( nums1[i] == nums2[j] ) {
            resul[p] = nums1[i];
            i++;
            j++;
            p++;
        } else if ( nums1[i] > nums2[j] ) {
            j++;
        } else {
            i++;
        }
    }

    *returnSize = p;


    return resul;
}