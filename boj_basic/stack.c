#include <stdio.h>
#include <string.h>

int stack[10000] = {0};
int idx = 0;

void push();
void pop();
void size();
void empty();
void top();

int main() {
	int N, i, n;
	char order[6] = {0};
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", order);
		if (strcmp("push", order) == 0) {
			scanf("%d", &n);
			push(n);
		}
		else if (strcmp("pop", order) == 0) {
			pop();
		}
		else if (strcmp("size", order) == 0) {
			size();
		}
		else if (strcmp("empty", order) == 0) {
			empty();
		}
		else if (strcmp("top", order) == 0) {
			top();
		}
	}
	return 0;
}

void push(int x) {
	stack[idx] = x;
	idx++;
}
void pop() {
	if (idx == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[idx - 1]);
		stack[idx - 1] = 0;
		idx--;
	}
}
void size() {
	printf("%d\n", idx);
}
void empty() {
	if (idx == 0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}
void top() {
	if (idx == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[idx - 1]);
	}
}
