#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int keyFunction(int n[], int key);
int keyFunction(int n[], int key) {
	
	int i;

	for (i = 0; i < 5; i++) {
		if (n[i] == key)
			return i;
	}

	return 0;
}
int main(void) {

	int n[5];
	int i, key;

	printf("Enter 5���� ����:");
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &n[i]);
	}

	printf("Enter a key:");
	scanf("%d", &key);

	if (keyFunction(n, key) == 0)
		printf("����.");
	else
		printf("%d��°�� �ִ�.\n", keyFunction(n, key)+1);

	return 0;
}