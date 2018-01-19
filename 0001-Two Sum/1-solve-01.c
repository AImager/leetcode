#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
	int *p = malloc(4*sizeof(int));
	for(int i=0;i<numsSize;i++) {
		for(int j=i+1;j<numsSize;j++) {
			if(nums[i]+nums[j]==target){
				p[0] = i;
				p[1] = j;
				return p;
			}
		}
	}
	return p;
}


int main(int argc, char *argv[]) {
	int nums[4] = {2,7,11,15};

	// int** test = malloc(sizeof(int(*))*2);
	// test[0] = malloc(sizeof(int)*3);
	// test[0][0] = 1;
	// test[0][1] = 2;
	// test[0][2] = 3;
	// test[1] = malloc(sizeof(int)*3);
	// test[1][0] = 4;
	// test[1][1] = 5;
	// test[1][2] = 6;
	// int (*(*changeTest)[2])[3] = (int (*(*)[2])[3])test;

	int numsSize = 4;
	int target = 9;
	int *p = malloc(4*sizeof(int));
	p = twoSum(nums, numsSize, target);
	printf("%d,%d",p[0],p[1]);
}