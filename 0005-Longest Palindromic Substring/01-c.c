#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int tempSum = 1;
    int endCursor = 0, inCheck = 0;
    int recordSum = 1, recordBegin = 0;
    char res[1000];
    while(1) {
        if (s[endCursor] == '\0') break;
        if (endCursor - 1 >= 0 && s[endCursor - 1] == s[endCursor] && inCheck == 0)  {
            tempSum++;
        } else if (endCursor - tempSum - 1 >= 0 && s[endCursor - tempSum - 1] == s[endCursor]) {
            inCheck = 1;
            tempSum+=2;
        } else if (tempSum > 1) {
            tempSum = 1;
            if (inCheck == 1) {
                while(endCursor > 1) {
                    if (s[endCursor-1] == s[endCursor-2]) endCursor--;
                    else break;
                }
            }
            inCheck = 0;
            continue;
        }
        if (tempSum > recordSum) {
            recordSum = tempSum;
            recordBegin = endCursor - tempSum + 1;
            printf("%d,%d\n",recordSum,recordBegin);
        }
        endCursor++;
    }
    char *result = (char*)malloc(sizeof(char)*(recordSum + 1)); 
    memcpy(result, &s[recordBegin], recordSum); 
    result[recordSum] = '\0';
    return result; 
}

int main () {
    char s[1000] = "abababa";
    char* res;
    res = longestPalindrome(s);
    // printf("%s", res);
    return 1;
}