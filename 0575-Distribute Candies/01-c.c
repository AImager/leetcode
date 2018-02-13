#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int distributeCandies(int* candies, int candiesSize) {
    int arr[200003], sum = 0;
    for (int i = 0; i < 200003; i++) arr[i] = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (arr[candies[i]+100000] == 0) {
            arr[candies[i]+100000] = 1;
            sum++;
        }
    }
    return sum > candiesSize/2 ? candiesSize/2 : sum;
}

int main(){
    int candies[SIZE] = {1,1,2,3};
    int res = distributeCandies(candies, 4);
    printf("%d",res);
    return 1;
}