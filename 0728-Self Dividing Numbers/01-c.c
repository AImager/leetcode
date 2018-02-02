#include <stdio.h>
#include <stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int temp,remainder,state = 0;
    int* returnVal = (int*)malloc(sizeof(int)*(right-left+1));
    *returnSize = 0;
    for(int i=left;i<=right;i++) {
        temp = i;
        state = 0;
        while(temp != 0) {
            remainder = temp%10;
            if (remainder == 0 || i%remainder != 0) {
                state = 1;
                break;
            }
            temp = temp/10;
        }    
        if(state == 0) {
            returnVal[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return returnVal;
}

int main() {
    int returnSize;
    int* res = selfDividingNumbers(1,100,&returnSize);
    for(int i=0;i<returnSize;i++) printf("%d\n",res[i]);
    return 1;
}