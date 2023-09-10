#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fib(int n, int* F) {
	if (n == 1 || n == 2)
		return 1;

	if (F[n - 1] == 0) // memo���� f(n-1)Ȯ��
		F[n - 1] = fib(n - 1, F); // memo�� ������ ȣ��
	if (F[n - 2] == 0) // memo���� Ȯ��
		F[n - 2] = fib(n - 2, F); // ������ ȣ�� -> ȣ�� Ƚ���� �ٿ���

	return F[n - 1] + F[n - 2];
}
int main(void) {

	int n, i;
	int* F;

	printf("�� ��°������ �Ǻ���ġ ����:");
	scanf("%d", &n);

	// memo �ʱ�ȭ
	F = (int*)malloc(sizeof(int*) * (n + 1));
	for (i = 1; i <= n; i++)
		F[i] = 0;

	for (i = 1; i <= n; i++)
		printf("%d ", fib(i, F));


	free(F);
	return 0;
}