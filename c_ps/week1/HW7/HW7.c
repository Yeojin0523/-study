#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo(int n[]);
void reverse(int n[]);
void echo(int n[]) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", n[i]);
	}
	printf("\n");
}
void reverse(int n[]) {
	int i;
	for (i = 4; i >= 0; i--) {
		printf("%d ", n[i]);
	}
	printf("\n");
}
int main(void) {

	int num[5];
	int i;

	printf("5���� ������ �Է��ϼ���:");
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}
	
	echo(num);
	reverse(num);

	return 0;
}