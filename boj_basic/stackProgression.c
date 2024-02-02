#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}node;

void push();
void pop();

int main() {
	int N, i;
	int idx = 0;
	int cnt = 0;
	int arr[100000] = {0};
	char plmi[200000] = {0};
	scanf("%d", &N);
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	
	// 늘어놓을 수열 받음
	for (i = 0; i < N; i++)
		scanf("%d", arr + i);
	// 1부터 N까지 push하면서 필요하면 pop하기
	// arr 1 2
	// sta 
	// ret 1 2
	// + - + -
	for (i = 1; i <= N; i++) {
		// printf("i %d\n", i);
		push(head, i);
		plmi[cnt] = '+';
		cnt++;
		while (head->next != NULL && arr[idx] == (head->next)->data) {
			pop(head);
			plmi[cnt] = '-';
			cnt++;
			idx++;
		}
		// printf("while end\n");
	}
	
	if (head->next == NULL) {
		for (i = 0; i < N * 2; i++) {
			printf("%c", plmi[i]);
			printf("\n");
		}
	}
	else {
		printf("NO");
	}
	
	// stack 연결리스트 free
	while(head->next != NULL) {
		node* del = head->next;
		head->next = (head->next)->next;
		free(del);
	}
}

void push(node* head, int x) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->next = head->next;
	newNode->data = x;
	head->next = newNode;
}
void pop(node* head) {
	node* del = head->next;
	head->next = (head->next)->next;
	free(del);
}