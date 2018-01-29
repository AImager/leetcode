#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1;
    int sum = 0, tmpSum;
    int lh = height[i], rh = height[j];
    while (i < j) {
        if (lh < rh) {
            tmpSum = lh * (j-i);
            while(i < j && height[i] <= lh) i++;
            lh = height[i];
        } else {
            tmpSum = rh * (j-i);
            while(i < j && height[j] <= rh ) j--;
            rh = height[j];
        }
        if ( tmpSum > sum ) sum = tmpSum;
    }
    return sum;
}

int main () {
    int height[100000] = {1,2,5,1,7,23,6,234,6,234,674657};
    int res = maxArea(height, 11);
    printf("%d", res);
    return 1;
}