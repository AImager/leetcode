#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int begin = 0, i = 0;
    char temp;
    while(1) {
        if (s[i] == '\0' || s[i] == ' ') {
            for(int j=begin;j<=i+begin-j-1;j++) {
                temp = s[i+begin-j-1];
                s[i+begin-j-1] = s[j];
                s[j] = temp;
            }
            begin = i+1;
        }
        if (s[i] == '\0') break;
        i++;
    }
    return s;
}

int main() {
    char *s = (char*)malloc(sizeof(char)*100);
    snprintf(s, 18, "%s", "Let's   take LeetCode contest");
    s = reverseWords(s);
    printf("%s",s);
    return 1;
}