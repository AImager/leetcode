#include <stdio.h>
#include <math.h>



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int* big = nums1;
	int* small = nums2;
	int bigSize = nums1Size, smallSize = nums2Size;
	if (nums1Size < nums2Size) {
		big = nums2;
		small = nums1;
		bigSize = nums2Size;
		smallSize = nums1Size;
	}

	int bigIndex = ((bigSize + 1)&0xFFFFFE) >> 1;
	int smallIndex = ((smallSize + 2)&0xFFFFFE) >> 1;
	int changeOffset = smallIndex;
	int valueB = -1, valueS = 100000000;

	while(1) {
		changeOffset = changeOffset >> 1;
		if (changeOffset < 1) break;
		if (big[bigIndex - 1] == small[smallIndex - 1]) {
			break;
		} else {
			if (big[bigIndex - 1] <= valueB && big[bigIndex - 1] >= valueS ) {
				valueB = big[bigIndex - 1];
			}
			if (small[smallIndex - 1] <= valueB && small[smallIndex - 1] >= valueS ) {
				valueS = small[smallIndex - 1];
			}
			if (valueS > valueB) {
				valueB = valueB ^ valueS;
				valueS = valueB ^ valueS;
				valueB = valueB ^ valueS;
			} 
			if (big[bigIndex - 1] > small[smallIndex - 1]){
				bigIndex -= changeOffset;
				smallIndex += changeOffset;
			} else {
				bigIndex += changeOffset;
				smallIndex -= changeOffset;
			}
		}
	}

	if ((bigSize + smallSize)&1 == 0) {
		return ;
	} else {
		return ;
	}
}


int main(int argc, char *argv[]) {
	int nums1[10000] = {4};
	int nums2[10000] = {1,2,3};
	int nums1Size = 1, nums2Size = 3;
	
	double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
}