#include <stdio.h>

int romanToInt(char* s) {
    int sum = 0;
    int number[13] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};  
    char flags[13][3] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0, j = 0;
    while(s[i] != '\0') {
        if((j&1) == 0) {
            if (s[i] == flags[j][0]) {
                i++;
                sum += number[j];
                continue;
            }
        } else {
            if (s[i] == flags[j][0] && s[i+1] == flags[j][1]) {
                i+=2;
                sum += number[j];
                continue;
            }
        }

        j++;
    }
    return sum;
}

int main() {
    printf("%d", romanToInt("DCCLXXXIX"));
    return 1;
}