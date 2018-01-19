#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
	char *p = (char*)malloc(sizeof(char)*10000);
	int len = 0, temp_div, temp_res;
	int i=0, j, index=0;
	int add = numRows==1?1:(i+ 2*numRows - 2);
	while(s[len]!='\0') len++;
	
	
	
	for(i=0;i< len;i+=add) {
		p[index] = s[i];
		index++;
	}
	
	
	if(numRows > 1) {
		for(j=1;j<numRows-1;j++) {
				for(i=j;i< len;i+=add) {
					p[index] = s[i];
					index++;
					if(i+2*abs(numRows-1-j) < len) {
						p[index] = s[i+2*abs(numRows-1-j)];
						index++;
					}
				}
			}

		for(i=numRows-1;i< len;i+=add) {
				p[index] = s[i];
				index++;
			}
	}
	
	p[index] = '\0';
	
	return p;
	
}


int main(int argc, char *argv[]) {
	char s[10000] = "A";
	char *p ;
	int numRows = 1;
	p = convert(s, numRows);
	printf("%s", p);
	

}