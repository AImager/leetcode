#include <stdio.h>
#include <stdlib.h>

int interval = 0x7FFFFFFF;

int compare(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void binSearch(int key, int* nums, int* sizes, int begin, int end) {
    if (begin > end) return;
    
    int mid = (begin + end)/2;
    
    if (nums[mid]> key) {
        if (nums[mid] - key < interval) interval = nums[mid] - key;
        binSearch(key, nums, sizes, begin, mid -1);
    }
        
    if (nums[mid]< key) {
        if (key - nums[mid] < interval) interval = key - nums[mid];
        binSearch(key, nums, sizes, mid+1, end);
    }
}

int threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    int *removalNums = (int*)malloc(sizeof(int)*numsSize);
    int *removalSize = (int*)malloc(sizeof(int)*numsSize);
    // int **returnNums = (int**)malloc(sizeof(int)*numsSize*(numsSize-1)/2);

    removalNums[0] = nums[0];
    removalSize[0] = 1;
    int index = 0;
    for(int i = 1;i < numsSize;i++) {
        if (nums[i] == nums[i-1]) {
            removalSize[index]++;    
        } else {
            index++;
            removalNums[index] = nums[i];
            removalSize[index] = 1;
        }
    }

    // for (int i =0;i<=index;i++) {
    //     printf("%d,%d\n",removalNums[i], removalSize[i]);
    // }
    // printf("%d",index);
    // return NULL;

    // int findIndex;
    *returnSize = 0;
    for(int i = 0;i<=index;i++) {
        removalSize[i]--;
        for (int j = i;j <= index;j++) {
            if(removalSize[j] >= 1) {
                removalSize[j]--;
                binSearch(0 - removalNums[i] - removalNums[j],removalNums,removalSize,j,index);

                removalSize[j]++;
            }
        }
        removalSize[i]++;
    }  
    // printf("%d\n", *returnSize);
    // return returnNums;
}

int main() {
    int arr[3000] = {};
    int returnSize = 0;
    int** result = threeSum(arr, 3000, &returnSize);
    return 1;
}