#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(const int*)a-*(const int*)b;
}

int arrayPairSum(int* nums, int numsSize) {
    int sum = 0;
    qsort(nums,numsSize,sizeof(int),compare);
    for(int i=1;i<numsSize;i+=2) sum+=nums[i-1];
    return sum;
}

int main() {
    int nums[100] = {-1,234,2452134,23222};
    int res = arrayPairSum(nums,4);
    printf("%d",res);
    return 1;
}