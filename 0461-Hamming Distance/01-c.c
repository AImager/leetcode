#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y) {
    int num=x^y, res = 0;
    for(int i=1;i<32;i++) res += (num >> (i-1) & 1);
    return res;
}

int main() {
    printf("%d", hammingDistance(0,1));
    return 1;
}