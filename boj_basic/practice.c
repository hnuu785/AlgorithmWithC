#include <stdio.h>

int main() {
	int N, M, i, j;
	int arr[100] = { 0 };
	int tmp[100] = { 0 };
	
	scanf("%d %d", &N, &M);
	
	for (int t1 = 0; t1 < N; t1++)
		arr[t1] = t1 + 1;
	
	for (int t1 = 0; t1 < M; t1++) {
		//printf("arr: ");
		
		for(int t2 = 0; t2 < N; t2++) {
			tmp[t2] = arr[t2];		
			//printf("%d ", arr[t2]);
		}
		
		//printf("\n");
		
		scanf("%d %d", &i, &j);
		
		for (int t2 = i - 1, t3 = 0; t2 <= j - 1; t2++, t3++) {
			arr[t2] = tmp[j - 1 - t3];
		}
	}
	
	for (int t1 = 0; t1 < N; t1++)
		printf("%d ", arr[t1]);
	// 배열 역순으로 만들기
	/*int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int newArr[10] = { 0 };
	
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	for (int i = 0; i < 10; i++) {
		newArr[i] = arr[9 - i];
		printf("%d ", newArr[i]);
	}*/
	
	return 0;
}