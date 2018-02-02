#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judgeCircle(char* moves) {
    int ud = 0, lr = 0;
    for(int i=0;moves[i] != '\0';i++){
        switch(moves[i]){
            case 'U':
                ud++;
                break;
            case 'D':
                ud--;
                break;
            case 'L':
                lr++;
                break;
            case 'R':
                lr--;
                break;
        }
    }
    if (ud == 0 && lr == 0) return 1;
    return 0; 
}

int main() {
    int a = judgeCircle("UD");
    return 1;
}