#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {
	int T, i, j, idx, wdx;
	char sentence[1001] = {0};
	char word[21] = {0};
	
	scanf("%d", &T);
	getchar();
	for (i = 0; i < T; i++) {
		idx = 0;
		fgets(sentence, sizeof(sentence), stdin);
		//gets(sentence);
		while (sentence[idx] != 0) {
			wdx = 0;
			while (sentence[idx] != ' ' && sentence[idx] != 0) {
				word[wdx] = sentence[idx];
				idx++; wdx++;
			}
			if (sentence[idx] == ' ') {
				//word[wdx] = 0;
				idx++;
				//wordFlip();
				for (j = wdx - 1; j >= 0; j--) {
					printf("%c", word[j]);
				}
				printf(" ");
			}
			if (sentence[idx] == 0) {
				for (j = wdx - 2; j >= 0; j--) {
					// fgets는 마지막에 \n도 저장하기 때문에
					printf("%c", word[j]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}