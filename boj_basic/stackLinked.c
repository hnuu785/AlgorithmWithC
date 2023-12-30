#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}node;

void push();
void pop();
void size();
void empty();
void top();

int main() {
	int N, i, n;
	char order[6] = {0};
	
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%s", order);
		
		if (strcmp("push", order) == 0) {
			scanf("%d", &n);
			push(head, n);
		}
		else if (strcmp("pop", order) == 0) {
			pop(head);
		}
		else if (strcmp("size", order) == 0) {
			size(head);
		}
		else if (strcmp("empty", order) == 0) {
			empty(head);
		}
		else if (strcmp("top", order) == 0) {
			top(head);
		}
	}
	// 연결리스트 전체 free하는법 연구성공
	// head node1 node2 node3
	while (head->next != NULL) {
		node* del = head->next;
		head->next = (head->next)->next;
		free(del);
	}
	free(head);
	return 0;
}

void push(node* head, int x) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = head->next;
	head->next = newNode;
}
void pop(node* head) {
	if (head->next == NULL) {
		printf("-1\n");
	}
	else {
		printf("%d\n", (head->next)->data);
		node* del = head->next;
		head->next = (head->next)->next;
		free(del);
	}
}
void size(node* head) {
	int cnt = 1;
	if (head->next == NULL) printf("0\n");
	else {
		node* search = head->next;
		while (search->next != NULL) {
			search = search->next;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
void empty(node* head) {
	if (head->next == NULL) printf("1\n");
	else printf("0\n");
}
void top(node* head) {
	if (head->next == NULL) printf("-1\n");
	else {
		printf("%d\n", (head->next)->data);
	}
}