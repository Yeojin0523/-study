#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int H(int n) {
	if (n == 0 || n == 1)
		return 1;
	for (int i = 0; i < n; i++)
		for()
		H(i)* H(n - j - i);
}
int main(void) {
	int n;
	printf("0���� ū ����:");
	scanf("%d", &n);
	printf("����� %d\n", H(n));
}