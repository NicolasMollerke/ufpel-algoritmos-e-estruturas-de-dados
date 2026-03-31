/*Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17] */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* runningSum(int* nums, int numsSize, int* returnSize) {

    int *resul = (int *) malloc(numsSize * sizeof(int));
    int soma=0;

    *returnSize = numsSize;

    for(int i=0; i < numsSize; i++){
        soma += nums[i];
        resul[i] = soma;
    }

    return resul;
}