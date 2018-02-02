#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s) {
    int len = strlen(s), temp, center = len/2;
    for(int i=0;i<center;i++) {
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
    return s;
}

int main(){
    char *s = (char*)malloc(sizeof(char)*100);
    snprintf(s, 2, "%s", "Let's take LeetCode contest");
    s = reverseString(s);
    printf("%s",s);
    return 1;
}