#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int findIf(int n1[], int n2[]);
int findIf(int n1[], int n2[]) {
	int i;

	for (i = 0; i < 5; i++) {
		if (n1[i] != n2[i])
			return 0;
	}
	return 1;
}
int main(void) {
	
	int n1[5], n2[5];
	int i;

	printf("Enter ù��° �迭:");
	for (i = 0; i < 5; i++) {
		scanf("%d", &n1[i]);
	}
	printf("Enter �ι�° �迭:");
	for (i = 0; i < 5; i++) {
		scanf("%d", &n2[i]);
	}

	if (findIf(n1, n2) == 1) {
		printf("�� ���� �迭�� ����.\n");
	}
	else
		printf("�� ���� �迭�� �ٸ���.\n");

	return 0;
}