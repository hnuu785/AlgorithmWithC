#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int M, i, j, cursor, size;
	char order, add;
	char str[600001];
	
	scanf("%s", str);
	scanf("%d", &M);
	getchar();
	cursor = strlen(str);
	size = cursor;
	for (i = 0; i < M; i++) {
		scanf("%c", &order);
		getchar();
		if (order == 'L') {
			if (cursor > 0)
				cursor--;
		}
		if (order == 'D') {
			if (cursor < size)
				cursor++;
		}
		if (order == 'B') {
			// .d.m|x.
			//  0 1 2
			if (cursor > 0) {
				//printf("cursor: %d\n", cursor);
				str[cursor - 1] = 0;
				for (j = cursor; j < size; j++) {
					//printf("is in for j %d\n", j);
					str[j - 1] = str[j];
				}
				str[size - 1] = 0;
				cursor--;
				size--;
			}
		}//.a.b|c.d.
		 // 0 1 2 3
		 //.a.b.x|c.d.
		 // 0 1 2 3 4
		if (order == 'P') {
			scanf("%c", &add);
			getchar();
			for (j = size; j > cursor; j--) {
				str[j] = str[j - 1];
			}
			str[cursor] = add;
			cursor++;
			size++;
		}
		//printf("str: %s, cursor: %d\n", str, cursor);
	}
	
	printf("%s", str);
}