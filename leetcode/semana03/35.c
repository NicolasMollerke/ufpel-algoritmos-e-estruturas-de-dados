#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target);

int main(){
    int *nums;
    int numsSize, target;
    
    int index = searchInsert(nums, numsSize, target);


}

int searchInsert(int* nums, int numsSize, int target) {
    for(int i = 0; i < numsSize; i++){
        if(nums[i] >= target){
            return i;
            break;
        } else if(i == numsSize - 1){
            return numsSize;
        }
    }

    return 0;
}