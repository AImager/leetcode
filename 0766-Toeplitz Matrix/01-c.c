#include <stdio.h>
#include <stdlib.h>

int isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int index;
    for(int i = matrixRowSize-2;i >= 0;i--) {
        index = 1;
        while(i+index < matrixRowSize && index < *matrixColSizes) {
            if (matrix[i+index][index] != matrix[i-1+index][index-1]) {
                return 0;
            }
        }
    }
    for(int i = 1;i<*matrixColSizes;i++) {
        index = 1;
        while(i+index < *matrixColSizes && index < matrixRowSize) {
            if (matrix[index][i+index] != matrix[index-1][i-1+index]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int *matrix[3] = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    int size = 4;
    printf("%d", isToeplitzMatrix(matrix, 3, &size));
    return 1;
}