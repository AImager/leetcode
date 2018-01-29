#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int j = 0;
    int index = -1;
    char tmp;

    if (strsSize == 0) return "";

    if (strsSize == 1) {
        index = strlen(strs[0]);
    } else {
        while(1) {
            tmp = strs[0][j];
            for(int i=0;i<strsSize;i++) {
                if(strs[i][j] != tmp || strs[i][j] == '\0') {
                    index = j;
                    break;
                }
            }
            j++;
            if(index != -1) break;
        }
    }

    char* res = (char*)malloc(sizeof(char)*(index+1));
    memcpy(res,strs[0],index);
    return res;
}

int main() {
    char *s[100] = {"cba", ""};
    char* str = longestCommonPrefix(s, 2);
    printf("%s",str);
    return 1;
}