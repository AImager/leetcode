#include <stdio.h>
#include <math.h>

int isPalindrome(int x) {
	double res = 0;
	if(x<10 && x>=0) return 1;
	if(x < 0 || x%10==0) return 0;
	while(x!=0) {
		res = res*10+(x%10);
		x=(int)(x/10);
		if(((int)res == (int)(x/10) && res != 0) || (int)res == (int)x){
			return 1;
		}
	}
	return 0;
}
	
int main(int argc, char *argv[]) {
	int x = 131000;
	printf("%d, %d", x,isPalindrome(x));
}