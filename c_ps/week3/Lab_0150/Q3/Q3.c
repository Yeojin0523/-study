#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {

	int a, c = 1, count = 1;

	printf("a���� �Է��ϼ���:");
	scanf("%d", &a);

	while (c % a != 0) {
		c = c * 10 + 1;
		count++;
	}
	printf("%d", count);

	return 0;
}