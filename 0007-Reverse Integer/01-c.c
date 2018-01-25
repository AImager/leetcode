#include <stdio.h>
#include <math.h>

int reverse(int x) {
	double res = 0;
	while(x!=0) {
		res = res*10+(x%10);
		x=(int)(x/10);
		printf("%lf,%d\n", res, x);
	}
	if(fabs(res) > 2147483647){
		return 0;
	}else {
		return (int)res;
	}
}

int main(int argc, char *argv[]) {
	int x=-2147483641, res;
	res = reverse(x);
	printf("%d,%d", x, res);
}