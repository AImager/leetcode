#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    char* ret = (char*)malloc(sizeof(char)*20);  
    int index = 0;
    int number[13] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};  
    char flags[13][3] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};  
        
    for(int i = 0; i < 13 && num > 0; i++){   
        if(num < number[i]) continue;  
        while(num >= number[i]){  
            num -= number[i];  
            if ((i&1) == 1) {
                ret[index] = flags[i][0];
                ret[index+1] = flags[i][1];
                index+=2;
            } else {
                ret[index] = flags[i][0];
                index++;
            }
        }  
    }
    ret[index] = '\0';  
    return ret;   
}

int main () {
    printf("%s",intToRoman(789));
    return 1;
}