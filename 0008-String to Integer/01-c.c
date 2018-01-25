#include <stdio.h>

int myAtoi(char* str) {
	double res=0;
	int fuhao=1, havein=0;

	for(int i=0;str[i]!='\0';i++) {
		if(str[i] == '-' && havein == 0){
			fuhao=-1;
			havein=1;
		}else if(str[i] == '+' && havein==0) {
			havein=1;
		}else if((int)(str[i])>='0' && (int)(str[i])<='9') {
			res=res*10+(int)((str[i])-48)*fuhao;
			havein=1;
		} else if(str[i] == ' ' && havein == 0) {
//			index=1;
		}else if(res > 2147483647){
			return 2147483647;
		}else if(res < -2147483648){
			return -2147483648;
		}else {
			return (int)res;
		}
	}
	if(res > 2147483647){
		return 2147483647;
	}else if(res < -2147483648){
		return -2147483648;
	}else {
		return (int)res;
	}
}


int main(int argc, char *argv[]) {
	char str[10000] = "     010";
	printf("%d",myAtoi(str));
}