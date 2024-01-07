#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}node;

int idx = 0;
char printer[100001] = {0};

void push();
void pop();

int main() {
	int n, i, j, ndx = 0;
	int arr[100000] = {0};
	int isOK = 1;
	node* H = (node*)malloc(sizeof(node));
	H->next = NULL;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	for (i = 0; i < n; i++) {
		push(H, i);
		while (arr[ndx] == (H->next)->data) {
			pop(H); ndx++;
		}
		if (arr[ndx] < (H->next)->data) {
			isOK = 0;
			break;
		}
	}
	if (isOK)
		for (i = 0; i < idx; i++)
			printf("%c\n", printer[i]);
	else {
		printf("NO");
	}
	//노드 전부 free
	while (H->next != NULL) {
		
	}
}

void push(node* H, int x) {
	node* new = (node*)malloc(sizeof(node));
	new->next = H->next;
	H->next = new;
	new->data = x;
	
	printer[idx] = '+';
	idx++;
}
void pop(node* H) {
	node* tmp = H->next;
	H->next = (H->next)->next;
	free(tmp);
	
	printer[idx] = '-';
	idx++;
}