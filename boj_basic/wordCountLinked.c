#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int cnt;
	char c;
	struct NODE* next;
}node;

void addNode(node* head, char c, int cnt);
void deleNode(node* head);
void checkNode(node* head);

int main() {
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	char word[1000001] = { 0 };
	scanf("%s", word);
	int i, j;
	int cnt = 0;
	for (i = 65; i <= 90; i++) {
		//printf("A~Z %c\n", i);
		cnt = 0;
		for (j = 0; j < strlen(word); j++) {
			//printf("cnt : %d ", cnt);
			if (i == word[j] || i + 32 == word[j]) {
				//printf("counted\n");
				cnt ++;
			}
		}
		addNode(head, i, cnt);
	}
	//checkNode(head);
	int max = -1;
	//printf("initializing max : %d\n", max);
	char output = 0;
	node* p = head->next;
	while (p != NULL) {
		//printf("p->c: %c, p->cnt: %d, max: %d, output: %c\n", p->c, p->cnt, max, output);
		if (max < p->cnt) {
			max = p->cnt;
			output = p->c;
		}
		else if (max == p->cnt) {
			output = '?';
		}
		p = p->next;
	}
	deleNode(head);
	printf("%c\n", output);
	return 0;
}

void addNode(node* head, char c, int cnt) {
	//printf("addNode run\n");
	node* newNode = (node*)malloc(sizeof(node));
	newNode->c = c;
	newNode->cnt = cnt;
	newNode->next = head->next;
	head->next = newNode;
}
void deleNode(node* head) {
	//printf("deleNode run\n");
	node* search = head->next;
	while (search->next != NULL) {
		search = head->next;
		head->next = search->next;
		free(search);
		//printf("it is deleted after head\n");
	}
	free(head->next);
	//printf("finished well\n");
}
void checkNode(node* head) {
	printf("checkNode run\n");
	node* search = head->next;;
	while (search != NULL) {
		printf("%c %d\n", search->c, search->cnt);
		search = search->next;
	}
}