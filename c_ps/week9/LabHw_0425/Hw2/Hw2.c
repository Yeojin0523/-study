#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Student {
	int id;
	int korean, english, math;
}stu;

int partition(struct Student* A, int p, int r, int subject) {
	int i, j;
	struct Student t;

	i = p - 1;

	if (subject == 4) {
		for (j = p; j < r; j++) {
			if (A[j].id < A[r].id) {
				i++;
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	if (subject == 2) {
		for (j = p; j < r; j++) {
			if (A[j].english > A[r].english) {
				i++;
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	if (subject == 3) {
		for (j = p; j < r; j++) {
			if (A[j].math > A[r].math) {
				i++;
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	if (subject == 1) {
		for (j = p; j < r; j++) {
			if (A[j].korean < A[r].korean) {
				i++;
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
	i++;
	t = A[i];
	A[i] = A[r];
	A[r] = t;
	return i;
}

void quickSort(struct Student* A, int p, int r, int subject) {
	if (p < r) {
		int q = partition(A, p, r, subject);
		quickSort(A, p, q - 1, subject);
		quickSort(A, q + 1, r, subject);
	}
}

int main(void) {
	int n;
	struct Student* s;
	int i;
	int subject;

	srand(time(NULL));

	printf("�л� ���� �Է��ϼ���:");
	scanf("%d", &n);

	s = malloc(sizeof(stu) * n);

	for (i = 0; i < n; i++) {
		s[i].id = i;
		s[i].english = rand() % 100 + 1;
		s[i].korean = rand() % 100 + 1;
		s[i].math = rand() % 100 + 1;
	}

	subject = 4;
	for (i = 0; i < n; i++) 
		printf("�й�: %2d\t����: %2d\t����: %2d\t����: %2d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
	printf("\n");

	while (1) {
		printf("���ı��� ����:<1 : ����, 2 : ����, 3: ����, 4:id<��������>, 0 : ������>");
		scanf("%d", &subject);

		if (subject != 0) {
			quickSort(s, 0, n - 1, subject);

			for(i = 0; i < n; i++)
			printf("�й�: %2d\t����: %2d\t����: %2d\t����: %2d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
		}
		else
			break;
	}
	free(s);
	return 0;
}