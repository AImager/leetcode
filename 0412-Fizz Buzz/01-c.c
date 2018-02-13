#include <stdio.h>
#include <stdlib.h>

char** fizzBuzz(int n, int* returnSize) {
    int size = 5;
    if (n > 10000000) size = 9;
    else if (n > 1000000) size = 8;
    else if (n > 100000) size = 7;
    else if (n > 10000) size = 6;
    char * = (char**)malloc(sizeof(char)*n*size);
}

int main() {
    int returnSize;
    char** res = fizzBuzz(5,&returnSize);
    return 1;
}