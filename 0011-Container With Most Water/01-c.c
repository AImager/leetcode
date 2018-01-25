#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * 这个版本超时
 */
int maxArea(int* height, int heightSize) {
    int sum = 0;
    int tempMaxDistance = 0;
    for(int i=1;i<=heightSize;i++) {
        tempMaxDistance = 0;
        for (int j=1;j<=heightSize;j++) {
            if (height[j-1] >= height[i-1] && abs(j-i) > tempMaxDistance) {
                tempMaxDistance = abs(j-i);
            }
        }
        if (tempMaxDistance * height[i-1] > sum) sum = tempMaxDistance * height[i-1];
    }
    return sum;
}

int main () {
    int height[100000] = {1,2,5,1,7,23,6,234,6,234,674657};
    int res = maxArea(height, 11);
    printf("%d", res);
    return 1;
}