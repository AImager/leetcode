#include <stdio.h>
#include <stdlib.h>

int patoi(char* str) {
    int res = 0, i = 0;
    if (str[0] == '-') i++;
    while(str[i] != '\0') res = res*10+str[i++]-'0';
    if (str[0] == '-') res = 0-res;
    return res;
}

int calPoints(char** ops, int opsSize){
    int nums[1003], index = 0, sum = 0;
    for (int i=0;i<opsSize; i++) {
        switch(ops[i][0]) {
            case 'D':
                nums[index] = nums[index-1]*2;
                index++;
                break;
            case 'C':
                index--;
                break;
            case '+':
                nums[index] = nums[index-1] + nums[index-2];
                index++;
                break;
            default:
                nums[index] = patoi(ops[i]);
                index++;
        }
    }
    for(int i=0;i<index;i++){
        // printf("%d\n",nums[i]);
        sum+=nums[i];
    }
    return sum;
}

int main() {
    char *str[100] = {"5","2","C","D","+"};
    // char *str[100] = {"5","-2","4","C","D","9","+","+"};
    int res = calPoints(str, 5);
    printf("%d", res);
    return 1;
}