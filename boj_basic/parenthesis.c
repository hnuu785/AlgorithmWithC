#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	int T, i, j, lc, rc, sw;
	char par[51] = {0};
	char c;
	
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%s", par);
		sw = 0; lc = 0; rc = 0;
		for (j = 0; *(par + j) != 0; j++) {
			if (*(par + j) == '(') lc++;
			if (*(par + j) == ')') rc++;
			if (lc < rc) sw = 1;
		}
		if (lc != rc) sw = 1;
		if (sw) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

/*
	)의 개수와 (의 개수가 일치
	끝은 ) 처음은 (
	왼쪽에서 오른쪽으로 세면서 )의 개수가 (의 개수보다 많아지면 잘못됨.
	
	( ) ) ( ( )
	((((((()))))))
*/    