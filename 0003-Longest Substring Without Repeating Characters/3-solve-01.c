#include <stdio.h>

int lengthOfLongestSubstring(char* s){
	int cursor_begin=0, temp_sum=0, sum=0;
	int index[128];
	for(int i=0;i<128;i++){
		index[i] = 0;
	}
	for(int cursor_end=0;s[cursor_end] != '\0';cursor_end++){
		if(index[s[cursor_end]] != 0){
			if(temp_sum>sum){
				sum = temp_sum;
			}
			
			temp_sum = cursor_end - index[s[cursor_end]] - 1;

			for(int j=cursor_begin;j<=index[s[cursor_end]];j++){
				index[s[j]] = 0;
			}
			cursor_begin = index[s[cursor_end]] + 1;
		}
		temp_sum++;
		index[s[cursor_end]] = cursor_end;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	char a[10000] = "sas";
	int len;
	len = lengthOfLongestSubstring(a);
	printf("%d", len+1);
}