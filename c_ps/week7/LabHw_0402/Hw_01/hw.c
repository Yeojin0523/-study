// selection(hw)
// �л��� ������ �����ϴ� ���α׷� �ۼ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Student {
	int id;
	int korean, english, math;
}Student;
void selectonSort(struct Student* A, int n) {
	int i, j, max, max_idx;
	struct Student temp;

	for (i = 0; i < n - 1; i++) {
		// max = A[0]; // ���⼭ ����
		max_idx = 0;

		for (j = 0; j < n - i; j++) {
			/*
			if (max < A[j]) {
				max = A[j];
				max_idx = j;
			}
			*/
			if (A[j].korean > A[max_idx].korean) {
				max_idx = j;
			}
		}
		temp = A[max_idx];
		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = temp;
	}
}
int main() {

	srand((unsigned)time(NULL));

	// n �Է� ����
	int n;

	scanf("%d", &n);

	if (n <= 0)
		return 0;
	// Student ����ü �迭�� �������� �Ҵ�
	struct Student* s = malloc(sizeof(Student) * n);

	if (!s)
		return 0;

	// ���� �ο�
	for (int i = 0; i < n; i++) {
		s[i].id = rand() % 100 + 1;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
		s[i].korean = rand() % 101;
	}
	
	selectonSort(s, n);

	for (int i = 0; i < n; i++) {
		printf("%d %d %d %d\n", s[i].korean, s[i].english, s[i].math, s[i].id);
	}

	free(s);
	return 0;
}