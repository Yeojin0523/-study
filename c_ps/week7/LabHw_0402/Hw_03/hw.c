// hw(bubble2)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Student
{
	int id;
	int math;
	int korean;
	int english;
}Stu;
bubbleSort(struct Student *s, int n, int standard) {
	int i, j;
	struct Student temp;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			
			if (standard == 4) {
				if (s[j].id > s[j + 1].id) {
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
			else if (standard == 1) {
				if (s[j].math < s[j + 1].math) {
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
			else if (standard == 2) {
				if (s[j].korean < s[j + 1].korean) {
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
			else if (standard == 3) {
				if (s[j].english < s[j + 1].english) {
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
		}
	}
}
/*
void swap(struct Student* s, int n, int standard) {
	
}
*/
int main(void) {

	srand((unsigned)time(NULL));

	int n;
	struct Student* s;
	int standard, i;
	
	printf("�л� ���� �Է��ϼ���:");
	scanf("%d", &n);

	s = malloc(sizeof(Stu) * n);

	if (n <= 0)
		return 0;
	if (!s) {
		printf("malloc error");
	}

	for (i = 0; i < n; i++) {
		s[i].id = rand() % 10;
		s[i].math = rand() % 101;
		s[i].korean = rand() % 101;
		s[i].english = rand() % 101;
	} 

	bubbleSort(s, n, 4);

	for (i = 0; i < n; i++) {
		printf("�й� : %d\t���� : %d\t���� : %d\t����: %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
	}

	do {
		printf("���� ���� ����:<1:����, 2:����, 3:����, 4: id(��������)>, 0: ������> :");
		scanf("%d", &standard);
		if (standard == 0)
			break;
		bubbleSort(s, n, standard);
		for (i = 0; i < n; i++) {
			printf("�й� : %d\t���� : %d\t���� : %d\t����: %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
		}

	} while (1);

	free(s);
	return 0;
}