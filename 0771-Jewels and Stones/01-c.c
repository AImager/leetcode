#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numJewelsInStones(char* J, char* S) {
    int sum[128], res = 0;
    for (int i=0;i<128;i++) sum[i] = 0;
    for(int i=0;i<strlen(S);i++) sum[S[i]]++;
    for(int i=0;i<strlen(J);i++) res+=sum[J[i]];
    return res;
}

int main() {
    char J[100] = "ada";
    char S[1000] = "";
    int num = numJewelsInStones(J,S);
    printf("%d", num);
    return 1;
}