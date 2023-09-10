// Selection Sort ��������
// 2023-04-12
#include<stdio.h>
void selectionSort(int* A, int n) { // �迭 A�� �����Ѵ�.

	int i, j;

	for (i = 0; i < n - 1; i++) { // n -1 �ݺ�
		int max = A[0];
		int max_index = 0;

		for (j = 1; j < n - i; j++) {
			if (max < A[j]) {
				max = A[j];
				max_index = j;
			}
		}
		// �� �迭 ���Ҹ� ��ȯ
		int temp = A[max_index];
		A[max_index] = A[n - 1 - i];
		A[n - 1 - i] = temp;
	} 
}
int main(void) {
	
	int array[10] = { 8, 5, 4, 3, 100, 99, 6, 7, 8, 9 };
	selectionSort(array, 10);

	for(int i = 0; i < 10; i++)
	printf("%d ", array[i]);

	return 0;
}