int comparar(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comparar);

    int meio = numsSize / 2;
    return nums[meio];
}