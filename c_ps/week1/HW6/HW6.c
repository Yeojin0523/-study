#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int num[6];
	int i;
	char ch = 0;

	while (ch != 'n')
	{
		srand(time(NULL));

		printf("*** �ζ� ��ȣ ������ ***\n");
		printf("���� ��ȣ: ");

		for (i = 0; i < 6; i++) {
			num[i] = rand() % 45 + 1;
		}
		for (i = 0; i < 6; i++) {
			printf("%d ", num[i]);
		}

		printf("\n�ٽ� �����Ͻðڽ��ϱ�?(y/n)");
		scanf(" %c", &ch);
	}
	
}