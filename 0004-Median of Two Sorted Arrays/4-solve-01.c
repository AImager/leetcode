#include <stdio.h>
#include <math.h>



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int *number1 = (int*)malloc(sizeof(int)*(nums1Size+1));
	int *number2 = (int*)malloc(sizeof(int)*(nums2Size+1));
	for(int i=0;i<nums1Size;i++) {
		number1[i] = nums1[i];
	}
	number1[nums1Size] = nums1[nums1Size];
	
	for(int i=0;i<nums2Size;i++) {
		number2[i] = nums2[i];
	}
	number2[nums2Size] = ;
	
//	int cursor1 = 0, cursor2 = 0;
//	int *number1, *number2;
//	double median = 0.0;
//	
//	if(nums1Size > nums2Size) {
//		nums1Size = nums1Size^nums2Size;
//		nums2Size = nums2Size^nums1Size;
//		nums1Size = nums1Size^nums2Size;
//		number1 = nums2;
//		number2 = nums1;
//	}else {
//		number1 = nums1;
//		number2 = nums2;
//	}
//	
//	
//	while(1){
//		if(cursor1 == nums1Size){
//			if((nums1Size + nums2Size)%2 == 1) {
//				median = (double)number2[(int)ceil((double)(nums1Size + nums2Size)/2) - 1 - nums1Size];
//			}else {
//				median = (double)(number2[(int)ceil((double)(nums1Size + nums2Size)/2) - 1 - nums1Size] + number2[(int)ceil((double)(nums1Size + nums2Size)/2) - nums1Size])/2;
//			}
//			return median;
//		}
//
//		if(cursor1 + cursor2 == ceil((double)(nums1Size + nums2Size)/2) - 1) {
//			if((nums1Size + nums2Size)%2 == 1) {
//				median = number1[cursor1] <= number2[cursor2] ? number1[cursor1] : number2[cursor2];
//			}else {
//				median = (double)(number1[cursor1] + number2[cursor2])/2;
//			}
//			return median;
//		}
//		
//		if(number1[cursor1] < number2[cursor2]) {
//			cursor1++;
//		} else if (number1[cursor1] > number2[cursor2]){
//			cursor2++;
//		} else {
//			if(cursor1 <= nums1Size-2 && cursor2 <= nums2Size-2 && number1[cursor1+1] > number2[cursor2+1]) {
//				cursor2++;
//			} else {
//				cursor1++;
//			}
//		}
//	}
}


int main(int argc, char *argv[]) {
	int nums1[10000] = {4};
	int nums2[10000] = {1,2,3};
	int nums1Size = 1, nums2Size = 3;
	
	double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	
	printf("%lf", median);
}