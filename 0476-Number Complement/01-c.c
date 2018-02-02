#include <stdio.h>
#include <stdlib.h>

int findComplement(int num) {
    int count = 1;
    while(num>>count) count++;
    return num^(0x7FFFFFFF>>(31-count));
}

int main () {
    printf("%d", findComplement(0x7FFEFFFE));
    return 1;
}